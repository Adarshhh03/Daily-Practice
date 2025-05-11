class Solution {
public:
    bool solve(int i,int j,string s,string p){
        bool op=false;
        if(i<0 && j>=0){
            while(j>=0){
                if(p[j]=='*'){
                 j--;
                }
                else{
                    break;
                }
            }
            return j==-1?true:false;
        }
        if(i>=0 && j<0){
          return false;
        }
        if(i<0 && j<0){
          return true;
        }
        if(s[i]==p[j]){
            op=solve(i-1,j-1,s,p);
        }
        else{
            if(p[j]=='*'){
                op=solve(i-1,j,s,p) || solve(i,j-1,s,p);
            }
            else if(p[j]=='?'){
                op=solve(i-1,j-1,s,p);
            }
            else{
                op=false;
            }
           
        }
        return op;
     }
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        
    vector<vector<bool>> dp(n+1,vector<bool> (m+1,false));
    dp[0][0]=true;
    for(int i=1;i<=m;i++){
        if(p[i-1]=='*'){
            dp[0][i]=true;
        }
        else{
            break;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            bool op=false;
            if(s[i-1]==p[j-1] || p[j-1]=='?'){
            op=dp[i-1][j-1];
            }
            else if(p[j-1]=='*'){
            op=dp[i-1][j] || dp[i][j-1];
            }
            else{
            op=false;
            }

            dp[i][j]=op;
        }
    }

    return dp[n][m];

    }
};