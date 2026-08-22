class Solution {
public:

    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));

        for(int i=n-1;i>=0;i--){
           for(int buy = 0;buy<=1;buy++){
             int profit;
            if(buy){
                profit = max(-arr[i]+dp[i+1][!buy],dp[i+1][buy]);
            }else{
                profit = max(arr[i]+dp[i+1][!buy],dp[i+1][buy]);
            }
            dp[i][buy] = profit;
           }
        }
        return dp[0][true];
        
    }
};