class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();

        int sum=0;
        int maxi=INT_MIN;
        int start=0;
        int end=0;
        for(int i=0;i<n;i++){
            if(sum==0)  start=i;
            sum+=nums[i];
            if(sum>maxi){
                maxi=sum;
                end=i;
            }

            if(sum<0){   //first we store the sum,and then we discard it if it is negative,as it is of no use
                sum=0;
            }
        }

        for(int i=start;i<=end;i++){
            cout<<nums[i]<<" ";
        }

        return maxi;
    }
};