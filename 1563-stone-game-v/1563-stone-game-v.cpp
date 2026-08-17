class Solution {
public:
   int func(int l,int r,vector<int>&arr,vector<int> & prefix,vector<vector<int>> &dp){
        // base case
        if(l==r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int ans = 0;
        //operation
        for (int i=l;i<r;i++) {
            int left = prefix[i+1] - prefix[l];
            int rig = prefix[r+1] - prefix[i+1];
            if (left<rig) {
                ans = max(ans,left + func(l,i,arr,prefix,dp));
            }else if (rig<left) {
                ans = max(ans,rig + func(i+1,r,arr, prefix,dp));
            }else {
                ans = max(ans,max(left+func(l,i,arr,prefix,dp),rig+func(i+1,r,arr,prefix,dp)));
            }
        }
        return dp[l][r]=ans;


    }
    int stoneGameV(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefix(n+1,0);
        for (int i=0;i<n;i++) {
            prefix[i+1] = prefix[i]+arr[i];
        }
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
       return   func(0,n-1,arr,prefix,dp);


    }
};