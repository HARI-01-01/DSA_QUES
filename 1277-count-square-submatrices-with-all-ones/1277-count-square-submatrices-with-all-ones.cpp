class Solution {
public:
    int countSquares(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();

        vector<vector<int>> dp(n,vector<int>(m,0));
        int ans = 0;
        for(int i=0;i<n;i++){
            dp[i][0] = arr[i][0];
            ans+=dp[i][0];
        }
        for(int i=1;i<m;i++){
            dp[0][i] = arr[0][i];
            ans+=dp[0][i];
        }


        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(arr[i][j] == 1){
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j])) + 1;
                    ans+=dp[i][j];
                }
            }
        }

        return ans;

        
    }
};