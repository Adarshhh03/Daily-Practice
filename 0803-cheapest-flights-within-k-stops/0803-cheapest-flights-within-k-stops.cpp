class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Build the adjacency list
        vector<pair<int, int>> adj[n];
        for (auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]}); // u -> v with cost w
        }

        // Min-heap for Dijkstra: {cost, node, stops}
        queue<tuple<int, int, int>> q;
        q.push({0, src, 0});

        // Distance array
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while (!q.empty()) {
            auto [cost, node, stops] = q.front();
            q.pop();

            if (stops > k) continue;

            for (auto &[neigh, wt] : adj[node]) {
                if (cost + wt < dist[neigh]) {
                    dist[neigh] = cost + wt;
                    q.push({cost + wt, neigh, stops + 1});
                }
            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};
