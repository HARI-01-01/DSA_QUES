class Solution {
public:
 
    int change(int tar, vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(tar+1,-1));
        //base case
        for(int i=0;i<=tar;i++){
            if(i%arr[0]==0){
                dp[0][i] = 1;
            }else{
                dp[0][i] = 0;
            }
        }

        for(int i=1;i<n;i++){
            for(int t=0;t<=tar;t++){
                long notTake = dp[i-1][t];
                long take = 0;
                if(arr[i]<=t) take =  dp[i][t-arr[i]];

                dp[i][t] = take+notTake;
            }
        }
        return dp[n-1][tar];
        
    }
};