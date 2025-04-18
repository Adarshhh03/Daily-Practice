class Solution {
public:
    void dfs(vector<vector<int>> &stones,vector<bool> &vis,int index){
        vis[index]=true;

        for(int i=0;i<stones.size();i++){
            int row=stones[index][0];  //row number of not visited stone
            int col=stones[index][1];  //col number of not visited stone
            if(!vis[i] && (row==stones[i][0] || col==stones[i][1])){
                dfs(stones,vis,i);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
     
        vector<bool> vis(n,false); //mark ith row and ith column
        int group=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){       //if that stone is not visited
                dfs(stones,vis,i);
                group++;
            }
        }

        return n-group;

    }
};