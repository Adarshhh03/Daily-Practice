class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mini=INT_MAX;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
         mini=min(prices[i],mini);
         int diff=prices[i]-mini;
         ans=max(diff,ans);
        }

        return ans;
    }
};