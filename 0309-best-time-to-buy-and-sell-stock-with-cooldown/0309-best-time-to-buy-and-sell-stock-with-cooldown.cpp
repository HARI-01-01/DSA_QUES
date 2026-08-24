class Solution {
public:
    // int func(int i,bool buy,vector<int> &arr,int n,vector<vector<int>> &dp){
    //     if(i>=n) return 0;
    //     if(dp[i][buy]!=-1) return dp[i][buy];

    //     if(buy){
    //         return dp[i][buy] = max(-arr[i]+func(i+1,!buy,arr,n,dp),func(i+1,buy,arr,n,dp));
    //     }
    //     return dp[i][buy] = max(arr[i]+func(i+2,!buy,arr,n,dp),func(i+1,buy,arr,n,dp));
    // }
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int b=0;b<=1;b++){
                if(b){
                    dp[i][b] = max(-arr[i]+dp[i+1][!b],dp[i+1][b]);
                } else dp[i][b] = max(arr[i]+dp[i+2][!b],dp[i+1][b]);
            }
        }
        return dp[0][true];
        
    }
};