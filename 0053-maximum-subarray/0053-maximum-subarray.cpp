class Solution {
public:
    int maxSubArray(vector<int>& nums) {
           int currSum = nums[0], maxSum = nums[0];
          // to print
          int mini=min(nums[0],0);
          int lastIndex=0;
          int startIndex=0,miniIndex=0;
        for (int i = 1; i < nums.size(); i++) {
            // currentSum = max(nums[i], currentSum + nums[i]);//here we are storing the max of prefixSum
            // maxSum = max(maxSum, currentSum);
            currSum+=nums[i];
            if(currSum-mini>maxSum){
                maxSum=currSum-mini;
                lastIndex=i;
                startIndex=miniIndex+1;
            }
           
           if(mini>currSum){
            mini=currSum;
            miniIndex=i;
           }

        }

    for(int i=startIndex;i<=lastIndex;i++){
        cout<<nums[i]<<" ";
    }

    return maxSum;
    }
};