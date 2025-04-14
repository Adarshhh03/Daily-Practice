class Solution {
public:
    vector<pair<int,int>> directions = {{0,1},{1,0},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};

    int dfs(int sr, int sc, vector<vector<int>>& grid, vector<vector<int>> &dis, int dist) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,pair<int,int>>> q; //dist->{i,j}

        q.push({1,{sr,sc}});
        while(!q.empty()){
        auto it=q.front();
        int wt=it.first;
        int r=it.second.first;
        int c=it.second.second;
        q.pop();

        for (auto &dir : directions) {
            int nr = r + dir.first;
            int nc = c + dir.second;

            if (nr >= 0 && nr < m && nc >= 0 && nc < n && (wt+1)<dis[nr][nc] && grid[nr][nc] == 0) {
             if(nr==m-1 && nc==n-1)    return wt+1;
             dis[nr][nc]=wt+1;
             q.push({wt+1,{nr,nc}});
            }
        }

        }

        return -1;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        if (m == 1 && n == 1 && grid[0][0]==1) return -1;
        if (m == 1 && n == 1 && grid[0][0]==0) return 1;
        if (grid[0][0] == 1 || grid[m-1][n-1] == 1) return -1;

        vector<vector<int>> dis(m, vector<int>(n, 1e9));
        int ans=dfs(0, 0, grid, dis, 1);

        return ans;
    }
};
