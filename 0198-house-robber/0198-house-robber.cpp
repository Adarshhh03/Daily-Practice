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
        vector<int> dp(n,-1);
        if(n==1)   return nums[0];
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        }
        return dp[n-1];
    }
};