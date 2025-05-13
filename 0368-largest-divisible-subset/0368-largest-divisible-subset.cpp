class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> hash(n,0);
       
       int lastIndex=0;
        sort(nums.begin(),nums.end());
        int maxi=1;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int p=i-1;p>=0;p--){
                if(nums[i]%nums[p]==0 && dp[p]+1>dp[i]){
                 dp[i]=dp[p]+1;
                 hash[i]=p;
                }
            }
            if(maxi<dp[i]){
                maxi=dp[i];
                lastIndex=i;
            }
        }
 
        vector<int> ans;
        while(hash[lastIndex]!=lastIndex){
            ans.push_back(nums[lastIndex]);
            lastIndex=hash[lastIndex];
        }
        ans.push_back(nums[lastIndex]);
        reverse(ans.begin(),ans.end());

        return ans;         
      
    }
};