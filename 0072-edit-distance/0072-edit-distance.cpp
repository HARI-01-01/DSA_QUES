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
       vector<int> prev(m+1,0),curr(m+1,0);
       
        for(int i=0;i<=m;i++){
            prev[i] = i;
        }
        for(int i=1;i<=n;i++){
            curr[0] = i;
            for(int j=1;j<=m;j++){

                if(s[i-1]==t[j-1]) curr[j] =  prev[j-1];
                else {
                int ins = curr[j-1];
                int del = prev[j];
                int rep = prev[j-1];

                    curr[j] = 1 + min(ins,min(del,rep));
                }
            }
            prev = curr;
        }

        return prev[m];
    }
};