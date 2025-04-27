class Solution {
public:
    int solve(int row, int col, vector<vector<int>>& triangle) {
        // Base conditions
        if (col < 0 || col > row) return 1e9; // invalid move
        if (row == 0 && col == 0) return triangle[0][0]; // start point

        // Recurrence
        int up = triangle[row][col] + solve(row-1, col, triangle);
        int leftDiagonal =triangle[row][col] +  solve(row-1, col-1, triangle);

        return min(up, leftDiagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m, 1e9)); 
        int mini = INT_MAX;
        dp[0][0]=triangle[0][0];
        for(int i=1;i<m;i++){
            dp[i][0]=triangle[i][0]+dp[i-1][0];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<=i;j++){
            dp[i][j]=triangle[i][j]+min(dp[i-1][j],dp[i-1][j-1]);
            }
        }
    
        for (int i = 0; i < m; i++) {
            mini = min(dp[m-1][i],mini);
        }
        return mini;
    }
};
