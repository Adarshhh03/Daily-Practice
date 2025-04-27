class Solution {
public:
    int solve(int firstIndex, int lastIndex, vector<int> &nums){
        int len = lastIndex - firstIndex + 1; // Number of houses
        if(len == 0) return 0;
        if(len == 1) return nums[firstIndex];
        
        vector<int> dp(len, 0);
        dp[0] = nums[firstIndex];
        dp[1] = max(nums[firstIndex], nums[firstIndex + 1]);
        
        for(int i = 2; i < len; i++){
            dp[i] = max(dp[i-1], nums[firstIndex + i] + dp[i-2]);
        }
        
        return dp[len-1];
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0]; // Only one house
        
        int includeFirst = solve(0, n-2, nums); // Exclude last house
        int includeLast = solve(1, n-1, nums);  // Exclude first house
        
        return max(includeFirst, includeLast);
    }
};
