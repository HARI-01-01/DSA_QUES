class Solution {
public:
    int func(int i,int j,string &s1,string &s2,vector<vector<int>> &dp){
        if(i<0 || j <0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]) return dp[i][j]= (1 + func(i-1,j-1,s1,s2,dp));
        return dp[i][j]=(0 + max(func(i-1,j,s1,s2,dp),func(i,j-1,s1,s2,dp)));
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        // memo
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return func(n-1,m-1,s1,s2,dp);
    }
};