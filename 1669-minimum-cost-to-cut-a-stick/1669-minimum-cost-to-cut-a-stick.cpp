class Solution {
public:
    // int solve(int index,int c,int n,vector<int>& cuts){
    //     if(index>c)   return 0;
    //     int mini=INT_MAX;
    //     for(int k=index;k<=c;k++){
    //        int val=cuts[c+1]-cuts[index-1]+solve(index,k-1,n,cuts)+solve(k+1,c,n,cuts);
    //        mini=min(val,mini);
    //     }

    //     return mini;
    // }
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());

    vector<vector<int>> dp(c+2,vector<int> (c+2,0));

    for(int i=c;i>=1;i--){
        for(int j=i;j<=c;j++){
            int mini=INT_MAX;
           for(int k=i;k<=j;k++){
            int val=cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j];
            mini=min(val,mini);
           }
           dp[i][j]=mini;
        }
    }

   
    return dp[1][c];
    }
};