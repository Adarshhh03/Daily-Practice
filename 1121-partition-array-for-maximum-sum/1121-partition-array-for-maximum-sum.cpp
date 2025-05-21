class Solution {
public:
    //int solve(int i,int n,vector<int> &arr,int k){
    //      if (i == n) return 0;
    //     int len=0;
    //     int maxi=INT_MIN,maxVal=INT_MIN;
    //   for(int j=i;j<min(n,i+k);j++){
    //     len++;
    //     maxi=max(arr[j],maxi);
    //     int val=len*maxi + solve(j+1,n,arr,k);
    //     maxVal=max(val,maxVal);
    //   }

    //   return maxVal;
    // }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
       int n=arr.size();
       vector<int> dp(n+1,0);

       for(int i=n-1;i>=0;i--){
        int len=0;
        int maxi=INT_MIN,maxVal=INT_MIN;

        for(int j=i;j<min(n,i+k);j++){
            len++;
            maxi=max(maxi,arr[j]);
            int val=maxi*len + dp[j+1];
            maxVal=max(val,maxVal);
        }

        dp[i]=maxVal;
       }
       return dp[0]; 
    }
};