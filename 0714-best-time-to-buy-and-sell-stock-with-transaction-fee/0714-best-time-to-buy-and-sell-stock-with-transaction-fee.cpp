class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
         int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int> (2,0));

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                int op;
                if(j==1){  //we can buy
                    op=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }
                else{  //we can sell
                    op=max(prices[i]+dp[i+1][1]-fee,dp[i+1][0]);
                }

                dp[i][j]=op;
            }
        }

        return dp[0][1];
    }
};