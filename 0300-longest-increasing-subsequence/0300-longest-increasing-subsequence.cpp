class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n,1);

        for(int i=1;i<n;i++){
             for(int j=i-1;j>=0;j--){
                if(arr[i]>arr[j]){
                    dp[i] = max(dp[i],1+dp[j]);
                }
            }
        }
        int ans = *max_element(dp.begin(),dp.end());
        return ans;
        
    }
};