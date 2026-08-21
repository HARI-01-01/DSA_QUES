class Solution {
public:
    bool func(int i,int j,string &s,string &p,vector<vector<int>> &dp){
        // base case
        if(i<0 && j<0) return true;
        if(i<0 && j>=0) {
             for(int k=0;k<=j;k++){
                if(p[k]!='*') return false;
            }
            return  true;
        }
        if(i>=0 && j<0){
           return false;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==p[j] || p[j]=='?') return dp[i][j] = func(i-1,j-1,s,p,dp);
        if(p[j]=='*') return dp[i][j] = func(i-1,j,s,p,dp) || func(i,j-1,s,p,dp);
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        // dp[0][0] = true;
        // for(int i=0;i<=m;i++){
        //     dp[0][i] = 
        // }
        return func(n-1,m-1,s,p,dp);
    }
};