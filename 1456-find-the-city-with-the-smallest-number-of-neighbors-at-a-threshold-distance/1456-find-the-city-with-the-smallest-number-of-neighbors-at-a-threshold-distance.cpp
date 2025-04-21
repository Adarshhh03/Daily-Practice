class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    
        vector<vector<int>> dist(n,vector<int> (n,1e9));
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            dist[u][v]=wt;
            dist[v][u]=wt;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    dist[i][j]=0;
                }
            }
        }
       for(int k=0;k<n;k++){
          for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
          }
       }
       int mini=INT_MAX;
       int node=-1;
       for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
          if(dist[i][j]<=distanceThreshold){
            count++;
          }
        }
        if(count<=mini){
        mini=count;
        node=i;
        }
       }
      return node;
    }
};