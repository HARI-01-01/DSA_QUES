class Solution {
public:
const int mod = 1e9+7;
    int minAbsoluteSumDiff(vector<int>& arr, vector<int>& nums) {
        int n =arr.size();
        long long ans = 0;
        int maxi = 0;
        vector<int> str = arr;
        sort(str.begin(),str.end());
        for(int i=0;i<n;i++){
            int org = abs(arr[i]-nums[i]);
            ans+= org;
            auto it = lower_bound(str.begin(),str.end(),nums[i]);
            int best = org;
            if(it!=str.end()){
                best = min(best,abs(*it-nums[i]));
            }
            if(it!=str.begin()){
                --it;
                best = min(best,abs(*it-nums[i]));
            }
            maxi = max(maxi,org-best);
        }
        return (ans-maxi)%mod;
    }
};