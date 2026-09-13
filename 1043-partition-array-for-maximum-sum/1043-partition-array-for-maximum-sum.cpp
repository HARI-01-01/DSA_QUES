class Solution {
public:
    // int func(int i,int k,vector<int>&arr,int n,vector<int> &dp){
    //     // base case
    //     if(i==n) return 0;
    //     if(dp[i]!= -1) return dp[i];

    //     int maxi = -1;
    //     int mm = -1;
    //     int len = 0;
    //     for(int j=i;j<min(n,i+k);j++){
    //         len++;
    //         mm = max(mm,arr[j]);
    //         int cost = (len)*mm + func(j+1,k,arr,n,dp);
    //         maxi = max(maxi,cost);
    //     }
    //     return dp[i] = maxi;

    // }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,0);

        for(int i=n-1;i>=0;i--){
            int maxi = -1;
            int mm = -1;
            int len = 0;
            for(int j=i;j<min(n,i+k);j++){
                len++;
                mm = max(mm,arr[j]);
                int cost = (len)*mm + dp[j+1];
                maxi = max(maxi,cost);
            }
            dp[i] = maxi;

        }
        return dp[0];
        
    }
};