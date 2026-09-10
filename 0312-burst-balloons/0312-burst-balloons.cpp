class Solution {
public:
    // int func(int i,int j,vector<int> &arr,vector<vector<int>>&dp){
    //     if(i>j) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];

    //     int maxi = -1;
    //     for(int k=i;k<=j;k++){
    //         int cost = arr[i-1]*arr[k]*arr[j+1] + func(i,k-1,arr,dp) + func(k+1,j,arr,dp);
    //         maxi = max(maxi,cost);
    //     }
    //     return dp[i][j] = maxi;
    // }
    int maxCoins(vector<int>& arr) {
        int n = arr.size();
        arr.insert(arr.begin(),1);
        arr.push_back(1);
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));

        for(int i=n;i>=1;i--){
            for(int j=1;j<=n;j++){
                int maxi = -1;
                if(i>j) continue;
                for(int k=i;k<=j;k++){
                    int cost = arr[i-1]*arr[k]*arr[j+1] + dp[i][k-1] + dp[k+1][j];
                    maxi = max(maxi,cost);
                }
                 dp[i][j] = maxi;
            }
        }


        return dp[1][n];
        
    }
};