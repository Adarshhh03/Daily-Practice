#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    void Disjoint(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findparent(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findparent(parent[node]);
    }

    void join(int u, int v) {
        int pu = findparent(u);
        int pv = findparent(v);
        if (pu == pv) return;
        if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        Disjoint(n);

        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mp.find(mail) == mp.end()) {
                    mp[mail] = i;
                } else {
                    join(i, mp[mail]);
                }
            }
        }

        unordered_map<int, vector<string>> mergedMail;
        for (auto& it : mp) {
            string mail = it.first;
            int node = it.second;
            int pnode = findparent(node);
            mergedMail[pnode].push_back(mail);
        }

        vector<vector<string>> ans;
        for (auto& it : mergedMail) {
            int idx = it.first;
            vector<string> temp = it.second;
            sort(temp.begin(), temp.end());
            temp.insert(temp.begin(), accounts[idx][0]);  // Add name at front
            ans.push_back(temp);
        }

        return ans;
    }
};
