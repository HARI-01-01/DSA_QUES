class Solution {
public:
bool func(int i,int bal,string &s,vector<vector<int>> &dp){
    // base case
    if(bal<0) return false;
    if(i == s.size()) return bal == 0;
    if(dp[i][bal]!=-1) return dp[i][bal];
    // try all thing
    if(s[i] == '(') return dp[i][bal] = func(i+1,bal+1,s,dp);
    else if(s[i] == ')') return dp[i][bal] = func(i+1,bal-1,s,dp);

    return dp[i][bal] = (func(i+1,bal+1,s,dp) || func(i+1,bal,s,dp) || func(i+1,bal-1,s,dp));
}
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return func(0,0,s,dp);
        
    }
};