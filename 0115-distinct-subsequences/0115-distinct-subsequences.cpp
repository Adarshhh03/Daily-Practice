class Solution {
public:
 const int MOD = 1e9 + 7;
    int solve(int i,int j,string s, string t){
        if(i<0 && j<0){
          return 1;
        }
        if(i<0 && j>=0){
            return 0;
        }
        if(i>=0 && j<0){
            return 1;
        }
        int op;
        if(s[i]==t[j]){
        op=solve(i-1,j-1,s,t)+solve(i-1,j,s,t);
        }
        else{
        op=solve(i-1,j,s,t);
        }

        return op;
    }
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
       
        //1st row is zero already,when str1 is empty,it will return 0;
        

        //fill 1st column, as we will always get 1 if str2 is empty
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int op;
                if(s[i-1]==t[j-1]){
                    op=(dp[i-1][j]+dp[i-1][j-1])%MOD;
                }
                else{
                    op=dp[i-1][j];
                }

                dp[i][j]=op;
            }
        }

        return dp[n][m];


    }
};