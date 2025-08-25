#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Build adjacency list (directed graph)
        vector<vector<pair<int,int>>> adj(n);
        for (auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        // {stops, node, cost}
        queue<tuple<int,int,int>> q;
        q.push({0, src, 0});

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while (!q.empty()) {
            auto [stops, node, cost] = q.front();
            q.pop();

            // explore neighbors if within stop limit
            for (auto &edge : adj[node]) {
                int v = edge.first, w = edge.second;
                if (stops + 1 <= k + 1 && cost + w < dist[v]) {
                    dist[v] = cost + w;
                    q.push({stops + 1, v, dist[v]});
                }
            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};
