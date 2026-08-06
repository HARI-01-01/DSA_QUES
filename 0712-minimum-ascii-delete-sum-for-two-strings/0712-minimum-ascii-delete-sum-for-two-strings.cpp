class Solution {
public:
    int func(int i,int j,string &s1,string &s2,vector<vector<int>> &dp,vector<vector<int>>&arr) {
    if (i==0 || j==0) {
        return 0;
    }
    if(arr[i][j]!=-1) return arr[i][j];
    int dig = 0;
    int l = 0;
    int r = 0;
    if (s1[i-1]!=s2[j-1]) {
         if (dp[i][j-1]==dp[i-1][j]) {
            l =func(i,j-1,s1,s2,dp,arr);
            r = func(i-1,j,s1,s2,dp,arr);
        }else if (dp[i][j-1]>dp[i-1][j]) {
            l = func(i,j-1,s1,s2,dp,arr);
        }else {
            r = func(i-1,j,s1,s2,dp,arr);
        }
    }else{
        dig =(int)s1[i-1] + func(i-1,j-1,s1,s2,dp,arr);
    }
    return arr[i][j] = max(dig,max(l,r));
}
int minimumDeleteSum(string s1, string s2) {

        int n = s1.size();
        int m = s2.size();
        // tabluation
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<=n;i++) dp[i][0] = 0;
        for(int i=0;i<=m;i++) dp[0][i] = 0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]= (1 + dp[i-1][j-1]);
                else dp[i][j]=(max(dp[i-1][j],dp[i][j-1]));
            }
        }
    // print_2(dp);
    vector<vector<int>> arr(n+1,vector<int>(m+1,-1));
    int maxi =func(n,m,s1,s2,dp,arr);
    
    // cout<<maxi<<endl;
    int total = 0;
    for (int i=0;i<n;i++) {
        total += s1[i];
    }
    for (int i=0;i<m;i++) {
        total += s2[i];
    }
    return total - (2*maxi);


}
};