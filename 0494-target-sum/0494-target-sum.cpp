class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int tar) {
        int n = arr.size();
        int sum = 0 ;
        for(auto it:arr) sum+=it;
        if(abs(tar)> sum) return 0;
        vector<vector<int>> dp(n,vector<int>(2*sum+1,0));
        dp[0][sum-arr[0]]++;
        dp[0][sum+arr[0]]++;

        for(int i=1;i<n;i++){
            for(int cu = -sum;cu<=sum;cu++){
                int way = 0;

                if(cu-arr[i]>=-sum){
                    way+= dp[i-1][cu-arr[i]+sum];
                }
                if(cu + arr[i]<=sum){
                    way+= dp[i-1][cu+arr[i]+sum];
                }
              
                dp[i][cu+sum] = way;
            }
        }
        return dp[n-1][tar+sum];

    }
};