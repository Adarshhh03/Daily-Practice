class Solution {
public:
//ci->current index, pi->previous index
    
    // int solve(int ci,int pi,int n ,vector<int> &nums){
    //     if(ci==n)   return 0;
    //     int op1=0,op2=0;
    //     if(pi==-1 || nums[pi]<nums[ci]){
    //     op1=1+solve(ci+1,ci,n,nums);
    //     }
    //     op2=0+solve(ci+1,pi,n,nums);
    //     return max(op1,op2);
    // }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();

       vector<vector<int>> dp(n+1,vector<int> (n+1,0));

       for(int i=n-1;i>=0;i--){
        for(int j=i-1;j>=-1;j--){   // all prev index beyond(after)i are gonna be 0,because its not possible
        //here the 0th index is considered as -1 in prev index so if from -1 to n-2 i.e 0 to n-1
            int op1=0,op2=0;
            if(j==-1 || nums[i]>nums[j]){
                op1=1+dp[i+1][i+1] ;
                //i+1 because we need to consider the 1st index in prev is at 3rd column and 1 index in curr is in 2nd index
            }

            op2=0+dp[i+1][j+1];

            dp[i][j+1]=max(op1,op2);
        }
       }
       return dp[0][0];
    }
};