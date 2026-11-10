class Solution {
public:
    // int mini = INT_MAX;
    // int func(int i,int &n,vector<int>&cost,vector<int>&dp){
    //     if(i>n) return INT_MAX;
    //     if(i==n) return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     int ans = INT_MAX;

    //     for(int j=1;j<=3;j++){
    //         if(i+j>n) break;

    //         int next = func(i+j,n,cost,dp);

    //         if(next!=INT_MAX){
    //         int c = cost[i+j-1] + pow(j,2);
    //         ans = min(ans,c+next);
    //         }
    //     }
    //     return dp[i] = ans;
    // }
    int climbStairs(int n, vector<int>& cost) {

        vector<int> dp(n+1,INT_MAX);
        dp[n] = 0;

        for(int i=n-1;i>=0;i--){
            int ans = INT_MAX;

            for(int j=1;j<=3;j++){
                if(i+j>n) break;

                int next = dp[i+j];

                if(next!=INT_MAX){
                int c = cost[i+j-1] + pow(j,2);
                ans = min(ans,c+next);
                }
            }
             dp[i] = ans;

        }
        return dp[0];
        
        
    }
};