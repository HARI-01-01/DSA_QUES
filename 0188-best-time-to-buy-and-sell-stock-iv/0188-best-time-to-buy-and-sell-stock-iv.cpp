class Solution {
public:
// int func(int i,int t,vector<int>&arr,int n,int k,vector<vector<int>> &dp){
//     if(i == n || t == 2*k) return 0;
//     if(dp[i][t]!=-1) return dp[i][t];

//     if(t%2==0){
//         //buy
//         return dp[i][t] = max(-arr[i]+func(i+1,t+1,arr,n,k,dp),func(i+1,t,arr,n,k,dp));
//     }
//     return dp[i][t] = max(arr[i]+func(i+1,t+1,arr,n,k,dp),func(i+1,t,arr,n,k,dp));
// }
    int maxProfit(int k, vector<int>& arr) {
        int n = arr.size();
        // vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));
            vector<int> curr(2*k+1,0),prev(2*k+1,0);
        for(int i=n-1;i>=0;i--){
            for(int t=2*k-1;t>=0;t--){
                if(t%2==0){
                //buy
                 curr[t] = max(-arr[i]+prev[t+1],prev[t]);
                }else curr[t] = max(arr[i]+prev[t+1],prev[t]);
            }
            prev = curr;
        }
        return prev[0];
    }
};