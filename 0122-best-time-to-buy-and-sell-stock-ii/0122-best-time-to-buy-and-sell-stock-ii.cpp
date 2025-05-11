class Solution {
public:
    // //0->we cant buy,we can sell
    // //1->we can buy
    // int solve(int index,int buy,vector<int> &prices,int n){
    //     int op=0;
    //   if(index==n)  return 0;
    //   if(buy==1){
    //     op= max(prices[index]+solve(index+1,0,prices,n) , 0+solve(index+1,1,prices,n));
    //   }
    //   if(buy==0){
    //     op= max(-prices[index]+solve(index+1,1,prices,n) , 0+solve(index+1,0,prices,n));
    //   }

    //   return op;
//}

    //0->we cant buy,we can sell
    //1->we can buy
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int> (2,0));

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                int op;
                if(j==1){  //we can buy
                    op=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }
                else{  //we can sell
                    op=max(prices[i]+dp[i+1][1],dp[i+1][0]);
                }

                dp[i][j]=op;
            }
        }

        return dp[0][1];
    }
};