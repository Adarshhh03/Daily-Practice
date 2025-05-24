class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        if(n==1)   return nums[0];
         int sum=0;
         int mini=0;
         int ans=INT_MIN;
        for(int i=0;i<n;i++){
            sum+=nums[i];
ans=max(ans,sum-mini);
            if(sum<mini){
                mini=sum;
            }
        
        }

        return ans;
    }
};