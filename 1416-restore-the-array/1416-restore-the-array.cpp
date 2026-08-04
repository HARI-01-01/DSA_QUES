class Solution {
public:
int mod = 1e9 + 7;

    int numberOfArrays(string s, int k) {
        int n = s.size();
        vector<int> dp(n+1,0);
        dp[n] = 1;

        for(int i=n-1;i>=0;i--){
            int ans = 0;
            long num = 0;
            if(s[i]=='0') {
                dp[i] = 0;
                 continue;
                }
           
            for(int j=i;j<s.size();j++){
                num = num * 10 + s[j]-'0';
                if(num > k) break;
                ans = (ans + dp[j+1])%mod;
            }
            dp[i] = ans;
            }
         return dp[0];
    }
};