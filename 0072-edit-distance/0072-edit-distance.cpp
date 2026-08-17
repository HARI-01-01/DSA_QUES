class Solution {
public:
// int func(int i,int j,string &s,string &t,vector<vector<int>> &dp){
//         if(j==0) return i;
//         if(i==0) return j;
//         if(dp[i][j]!=-1) return dp[i][j];

//         if(s[i-1]==t[j-1]) return dp[i][j] =  func(i-1,j-1,s,t,dp);
//         int ins = 1 + func(i,j-1,s,t,dp);
//         int del = 1 + func(i-1,j,s,t,dp);
//         int rep = 1 + func(i-1,j-1,s,t,dp);

//         return dp[i][j] = min(ins,min(del,rep));
//     }
    int minDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0] = i;
        }
        for(int i=0;i<=m;i++){
            dp[0][i] = i;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){

                if(s[i-1]==t[j-1]) dp[i][j] =  dp[i-1][j-1];
                else {
                int ins = 1 + dp[i][j-1];
                int del = 1 + dp[i-1][j];
                int rep = 1 + dp[i-1][j-1];

                    dp[i][j] = min(ins,min(del,rep));
                }
            }
        }

        return dp[n][m];
    }
};