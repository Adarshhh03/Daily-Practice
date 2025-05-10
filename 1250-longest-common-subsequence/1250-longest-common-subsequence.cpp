class Solution {
public:
    // int solve(int index1,int index2,string text1, string text2){
    //     if(index1<0 || index2<0){
    //         return 0;
    //     }
    //     int op1=0,op2=0;
    //     if(text1[index1]==text2[index2]){
    //   op1=1+solve(index1-1,index2-1,text1,text2);
    //     }
    //     else{
    //     op2=max(solve(index1-1,index2,text1,text2),solve(index1,index2-1,text1,text2));
    //     }

    //     return  max(op1,op2);
    // }
    int longestCommonSubsequence(string text1, string text2) {
        int index1=text1.length();
        int index2=text2.length();
        vector<vector<int>> dp(index1+1,vector<int> (index2+1,0));
        for(int i=1;i<=index1;i++){
            for(int j=1;j<=index2;j++){
                int op;
                if(text1[i-1]==text2[j-1]){
                 op=1+dp[i-1][j-1];
                }
                else{
                    op=max(dp[i-1][j],dp[i][j-1]);
                }

                dp[i][j]=op;
            }
        }

        return dp[index1][index2];
    }
};