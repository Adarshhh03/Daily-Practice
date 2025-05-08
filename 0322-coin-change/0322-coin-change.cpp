class Solution {
public:
    // int solve(int index,vector<int>& coins, int amount,int n){
    //     if(index==0){
    //         if(amount%coins[0]==0){
    //             return amount/coins[0];
    //         }
    //         else{
    //             return 1e9;
    //         }
    //     }

    //     //NotTake
    //     int notTake=solve(index-1,coins,amount,n);
    //     //take
    //     int take=1e9;
    //     if(coins[index]<=amount){
    //         take=1+solve(index,coins,amount-coins[index],n);
    //     }

    //     return min(take,notTake);
    // }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,1e9));

        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0){
                dp[0][i]=i/coins[0];
            }
        }
        for(int i=1;i<n;i++){
          for(int j=0;j<=amount;j++){
          int notTake=0+dp[i-1][j];

          int take=1e9;
          if(coins[i]<=j){
            take=1+dp[i][j-coins[i]];
          }

          dp[i][j]=min(take,notTake);
          }
        }

        return dp[n-1][amount]!=1e9?dp[n-1][amount]:-1;
    }
};