class Solution {
public:
    bool func(int i,int j,string &s,string &p,vector<vector<int>> &dp){
        // base case
        if(i==0 && j==0) return true;
        if(i==0 && j>0) {
             for(int k=1;k<j;k++){
                if(p[k]!='*') return false;
            }
            return  true;
        }
        if(i>0 && j==0){
           return false;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i-1]==p[j-1] || p[j-1]=='?') return dp[i][j] = func(i-1,j-1,s,p,dp);
        if(p[j-1]=='*') return dp[i][j] = func(i-1,j,s,p,dp) || func(i,j-1,s,p,dp);
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        dp[0][0] = true;
        for(int i=1;i<=n;i++){
            dp[i][0] = false; 
        }
        for(int i=1;i<=m;i++){
            bool fl = true;
            for(int k=1;k<=i;k++){
                if(p[k-1]!='*') {
                    fl = false;
                    break;
                }
            }
            dp[0][i] = fl;
        }


        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?') dp[i][j] = dp[i-1][j-1];
                else if(p[j-1]=='*') dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else dp[i][j] = false;
            }
        }
        return dp[n][m];
    }
};