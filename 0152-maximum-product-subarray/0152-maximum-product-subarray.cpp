class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mini=nums[0];
        int maxi=nums[0];
        int ans=nums[0];

        for(int i=1;i<nums.size();i++){
            
            int temp=max(nums[i],max(nums[i]*maxi,nums[i]*mini));
            //we use temp to not update before using it for mini
            mini=min(nums[i],min(nums[i]*maxi,nums[i]*mini));
            maxi=temp;
            ans=max(ans,maxi);
        }


        return ans;
    }
};