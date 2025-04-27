class Solution {
public:
    int solve(int firstIndex,int lastIndex,vector<int> &nums,vector<int> &dp){
        
        if(firstIndex>lastIndex){
            return 0;
        }
        if(dp[firstIndex]!=-1)   return dp[firstIndex];
        int take=nums[firstIndex]+solve(firstIndex+2,lastIndex,nums,dp);
        int notTake=solve(firstIndex+1,lastIndex,nums,dp);

        return dp[firstIndex]=max(take,notTake);
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        // int includeFirst=solve(0,n-2,nums,0);      
        // int includeLast=solve(1,n-1,nums,0);            
        vector<int> dp(n,-1);

        solve(0,n-1,nums,dp);

        return dp[0];
    }
};