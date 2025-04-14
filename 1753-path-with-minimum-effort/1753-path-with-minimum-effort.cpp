class Solution {
public:
   vector<pair<int,int>> directions={{1,0},{0,1},{-1,0},{0,-1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        
        vector<vector<int>> diff(m,vector<int> (n,1e9));
        diff[0][0]=0;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,0}});
        int mini=INT_MAX;

        while(!q.empty()){
         auto it=q.front();
         int d=it.first;
         int r=it.second.first;
         int c=it.second.second;
         q.pop();
         for(auto dir:directions){
            int nr=r+dir.first;
            int nc=c+dir.second;

             if (nr >= 0 && nr < m && nc >= 0 && nc < n ) {
             int newDiff=max(abs(heights[r][c]-heights[nr][nc]),d);

             if(newDiff < diff[nr][nc]){
             diff[nr][nc]=newDiff;
             q.push({newDiff, {nr,nc}});
             }
            }

        }
    }
   
      return diff[m-1][n-1];
    }
};