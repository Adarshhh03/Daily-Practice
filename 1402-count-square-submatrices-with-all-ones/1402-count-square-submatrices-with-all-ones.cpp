class Solution {
public:
    int solve(int i,int j,vector<vector<int>> &matrix){
       if(matrix[i][j]==0)   return 0;

        if(i==0)  return matrix[0][j];
        if(j==0)   return matrix[i][0];
 
        int val=min({solve(i-1,j,matrix),solve(i-1,j-1,matrix),solve(i,j-1,matrix)});

        return matrix[i][j]+val;
    }
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int ans=0;

        vector<vector<int>> dp(m+1,vector<int> (n+1,0));
       for(int i=0;i<m;i++){
        dp[i][0]=matrix[i][0];
       }
        for(int i=1;i<n;i++){
        dp[0][i]=matrix[0][i];
       }

         for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]!=0){
                    dp[i][j]=matrix[i][j]+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                }
            }
         }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
            ans+=dp[i][j];
            }
        }
        return ans;
    }
};