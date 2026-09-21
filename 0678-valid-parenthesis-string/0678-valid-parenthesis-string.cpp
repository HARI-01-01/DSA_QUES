class Solution {
public:
// bool func(int i,int bal,string &s,vector<vector<int>> &dp){
//     // base case
//     if(bal==0) return false;
//     if(i == s.size()) return bal == 1;
//     if(dp[i][bal]!=-1) return dp[i][bal];
//     // try all thing
//     if(s[i] == '(') return dp[i][bal] = func(i+1,bal+1,s,dp);
//     else if(s[i] == ')') return dp[i][bal] = func(i+1,bal-1,s,dp);

//     return dp[i][bal] = (func(i+1,bal+1,s,dp) || func(i+1,bal,s,dp) || func(i+1,bal-1,s,dp));
// }
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,false));

        
        dp[n][0]=true;
        
        for(int i=n-1;i>=0;i--){
            for(int j=n;j>=0;j--){
                if(s[i] == '(' )  {

                    if(j+1<=n) dp[i][j] = dp[i+1][j+1];
                }else if(s[i] == ')') {
                     if(j>0)dp[i][j] = dp[i+1][j-1];
                }else {
                    bool asOpen = false;
                    bool empty = dp[i+1][j];
                    bool asClose = false;

                    if(j+1<=n) asOpen = dp[i+1][j+1];
                    if(j>0) asClose = dp[i+1][j-1];

                    dp[i][j] = asOpen || empty || asClose;
                }
            }
        }
        return dp[0][0];
        
    }
};