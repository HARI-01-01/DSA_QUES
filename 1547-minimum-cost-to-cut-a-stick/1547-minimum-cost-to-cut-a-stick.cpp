class Solution {
public:
    // int func(int i,int j,vector<int> &arr,vector<vector<int>> &dp){
    //     if(i>j) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];

    //     int mini = 1e9;
        
    //     for(int k=i;k<=j;k++){
    //         int cost = arr[j+1] - arr[i-1] + func(i,k-1,arr,dp)+func(k+1,j,arr,dp);
    //          mini = min(mini,cost);
    //     }

    //     return dp[i][j] = mini;
    // }
    int minCost(int n, vector<int>& arr) {
        int m = arr.size();
        sort(arr.begin(),arr.end());
        arr.insert(arr.begin(),0);
        arr.push_back(n);
        vector<vector<int>> dp(m+2,vector<int>(m+2,0));

        for(int i=m;i>=1;i--){
            for(int j=1;j<=m;j++){
                if(i>j) continue;
                int mini = 1e9;
        
            for(int k=i;k<=j;k++){
                int cost = arr[j+1] - arr[i-1] + dp[i][k-1]+dp[k+1][j];
                mini = min(mini,cost);
            }

             dp[i][j] = mini;
            }
        }

        return dp[1][m];
        
    }
};