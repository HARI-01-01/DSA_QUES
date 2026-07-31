class Solution {
public:
    int coinChange(vector<int>& arr, int tar) {
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(tar+1,-1));

        for(int t=0;t<=tar;t++){
            if(t%arr[0]==0){
                dp[0][t] = t/arr[0];
            }else{
                dp[0][t] = 1e9;
            }
        }

        for(int i=1;i<n;i++){
            for(int t=0;t<=tar;t++){
                int notTake= 0 + dp[i-1][t];
                int take = INT_MAX;
                if(arr[i]<=t) take = 1+ dp[i][t-arr[i]];

                 dp[i][t] = min(take,notTake);
            }
        }

        return dp[n-1][tar] >= 1e9 ? -1:dp[n-1][tar];
    }
};