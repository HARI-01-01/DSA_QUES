class Solution {
public:
    int func(int i,vector<int> &arr,int k,int n,bool buy,vector<vector<int>> &dp){
        if(n==i) return 0;
        if(dp[i][buy]!= -1) return dp[i][buy];

        if(buy){
            return dp[i][buy] = max(-arr[i] + func(i+1,arr,k,n,!buy,dp),func(i+1,arr,k,n,buy,dp));
        }else{
            return dp[i][buy] = max(arr[i]-k + func(i+1,arr,k,n,!buy,dp),func(i+1,arr,k,n,buy,dp));
        }
    }
    int maxProfit(vector<int>& arr, int k) {
        int n = arr.size();
        // vector<vector<int>> dp(n+1,vector<int>(2,0));
        vector<int> curr(2,0),prev(2,0);

        for(int i=n-1;i>=0;i--){
            
               
                     curr[0] = max(-arr[i] + prev[1],prev[0]);
            
                     curr[1] = max(arr[i]-k + prev[0],prev[1]);
        
            
            prev = curr;
        }
        return prev[0];
    }
};