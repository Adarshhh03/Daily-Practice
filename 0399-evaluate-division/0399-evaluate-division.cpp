class Solution {
public:
    double bfs(string num, string den, unordered_map<string, vector<pair<string, double>>> &adj) {
        if (adj.find(num) == adj.end() || adj.find(den) == adj.end()) return -1.0;

        queue<pair<string, double>> q;
        unordered_set<string> visited;
        q.push({num, 1.0});
        visited.insert(num);

        while (!q.empty()) {
            auto [curr, val] = q.front();
            q.pop();

            if (curr == den) return val;

            for (auto& [neigh, weight] : adj[curr]) {
                if (!visited.count(neigh)) {
                    visited.insert(neigh);
                    q.push({neigh, val * weight});
                }
            }
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, 
                                vector<double>& values, 
                                vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;

        // Build the adjacency list
        for (int i = 0; i < equations.size(); ++i) {
            string A = equations[i][0];
            string B = equations[i][1];
            double val = values[i];
            adj[A].push_back({B, val});
            adj[B].push_back({A, 1.0 / val});
        }

        vector<double> ans;
        for (auto& q : queries) {
            string num = q[0];
            string den = q[1];
            ans.push_back(bfs(num, den, adj));
        }

        return ans;
    }
};
