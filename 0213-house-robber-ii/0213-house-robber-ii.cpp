class Solution {
public:
    int solve(int firstIndex, int lastIndex, vector<int> &nums, vector<int> &dp){
        if(firstIndex > lastIndex){
            return 0;
        }
        if(dp[firstIndex] != -1) return dp[firstIndex];

        int take = nums[firstIndex] + solve(firstIndex + 2, lastIndex, nums, dp);
        int notTake = solve(firstIndex + 1, lastIndex, nums, dp);

        return dp[firstIndex] = max(take, notTake);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0]; // Only one house
        
        vector<int> dp1(n, -1); 
        vector<int> dp2(n, -1);

        // Case 1: Rob from house 0 to n-2 (excluding last)
        int includeFirst = solve(0, n-2, nums, dp1);

        // Case 2: Rob from house 1 to n-1 (excluding first)
        int includeLast = solve(1, n-1, nums, dp2);

        return max(includeFirst, includeLast);
    }
};
