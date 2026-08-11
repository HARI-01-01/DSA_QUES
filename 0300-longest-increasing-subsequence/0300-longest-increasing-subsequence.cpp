class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();

        // i is shifted by +1
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= n; j++) {

                int take = 0;

                if(j == n || arr[j] > arr[i]) {
                    take = 1 + dp[i][i];
                }

                int notTake = dp[i][j];

                dp[i + 1][j] = max(take, notTake);
            }
        }

        return dp[n][n];
    }
};