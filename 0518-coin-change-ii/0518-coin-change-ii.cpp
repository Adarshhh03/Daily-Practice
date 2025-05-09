class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        const long long LIMIT = 1e18; // cap to avoid overflow
        vector<vector<long long>> dp(n, vector<long long>(amount + 1, 0));

        // Base case: using only the first coin
        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0) {
                dp[0][i] = 1;
            }
        }

        // Fill the DP table
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= amount; j++) {
                long long notTake = dp[i - 1][j];
                long long take = 0;
                if (coins[i] <= j) {
                    take = dp[i][j - coins[i]];
                }

                dp[i][j] = take + notTake;

                // cap result to avoid signed overflow
                if (dp[i][j] > LIMIT) {
                    dp[i][j] = LIMIT;
                }
            }
        }

        return static_cast<int>(dp[n - 1][amount]);  // You can also return dp[n-1][amount] as long long
    }
};
