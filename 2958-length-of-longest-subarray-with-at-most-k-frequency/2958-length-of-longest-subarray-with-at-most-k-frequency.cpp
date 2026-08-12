class Solution {
public:
    int maxSubarrayLength(vector<int>& arr, int k) {
        int n = arr.size();
        // number and cnt
        unordered_map<int,int> mp;
        int ans = -1;
        int l = 0;
        for(int r = 0;r<n;r++){
            mp[arr[r]]++;
            if(mp[arr[r]]>k){
                while(l<=r && mp[arr[r]]>k){
                    mp[arr[l]]--;
                    l++;
                }
            }
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};