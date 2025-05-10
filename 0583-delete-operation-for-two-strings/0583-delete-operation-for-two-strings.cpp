class Solution {
public:
    int minDistance(string word1, string word2) {
          int len1=word1.length();
        int len2=word2.length();
        vector<vector<int>> dp(len1+1, vector<int> (len2+1,0));

        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                int op1=0,op2=0;
                if(word1[i-1]==word2[j-1]){
                   op1=1+dp[i-1][j-1];
                }
                else{
                    op2=max(dp[i-1][j],dp[i][j-1]);
                }
                dp[i][j]=max(op1,op2);
            }
        }
        int lcs=dp[len1][len2];
        return (len1-lcs)+(len2-lcs);
    }
};