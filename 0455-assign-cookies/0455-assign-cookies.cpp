class Solution {
public:
    int solve(vector<int>& g, vector<int>& s,int n,int m,int ind1,int ind2){
        if(ind1>=n || ind2>=m)  return 0;
        int take=0,notTake=0;
        if(g[ind1]<=s[ind2]){
            take=1+solve(g,s,n,m,ind1+1,ind2+1);
        }
        else{
            notTake=0+solve(g,s,n,m,ind1,ind2+1);
        }

        return max(take,notTake);
    }
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size();
        int m=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        return solve(g,s,n,m,0,0);
    }
};