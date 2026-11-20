class Solution {
public:

    int maxSelectedElements(vector<int>& arr) {

        sort(arr.begin(),arr.end());
        unordered_map<int,int>dp;
        int ans= 0 ;
        for(int i:arr){
            dp[i+1] = dp[i]+1;
            dp[i] = dp[i-1]+1;
            ans = max(ans,max(dp[i],dp[i+1]));
        }

        return ans;
    }
};