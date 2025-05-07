class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();

        if (totalSum % 2 != 0) return false;

        int targetSum = totalSum / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(targetSum + 1, false));

        for (int i = 0; i <= n; ++i) {
            dp[i][0] = true;  // Sum 0 is always possible
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= targetSum; ++j) {
                bool notTake = dp[i - 1][j];
                bool take = false;
                if (j >= nums[i - 1]) {
                    take = dp[i - 1][j - nums[i - 1]];
                }
                dp[i][j] = take || notTake;
            }
        }

        return dp[n][targetSum];
    }
};
