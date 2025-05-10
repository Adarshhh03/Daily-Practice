class Solution {
public:
    int minInsertions(string s) {
        string t = s; 
       reverse(t.begin(), t.end());

        int len=s.length();
        vector<vector<int>> dp(len+1, vector<int> (len+1,0));

        for(int i=1;i<=len;i++){
            for(int j=1;j<=len;j++){
                int op;
                if(s[i-1]==t[j-1]){
                   op=1+dp[i-1][j-1];
                }
                else{
                    op=max(dp[i-1][j],dp[i][j-1]);
                }
                dp[i][j]=op;
            }
        }

        return len-dp[len][len];
    }
};