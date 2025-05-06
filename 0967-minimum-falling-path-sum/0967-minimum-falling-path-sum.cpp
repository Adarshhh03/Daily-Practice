#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            dp[0][i] = matrix[0][i];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int up = matrix[i][j] + dp[i - 1][j];
                int ld = (j < n - 1) ? matrix[i][j] + dp[i - 1][j + 1] : INT_MAX;
                int rd = (j >= 1) ? matrix[i][j] + dp[i - 1][j - 1] : INT_MAX;
                
                dp[i][j] = min(up, min(ld, rd));
            }
        }

        int ans = INT_MAX;
        for (int num : dp[n - 1]) {
            ans = min(num, ans);
        }
        return ans;
    }
};