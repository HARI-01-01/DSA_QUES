class Solution {
public:
    const int mod = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        long long odd = 0, sum = 0;

        for(int i=0;i<n;i++){
            sum+=arr[i];
            odd+= sum%2;
        }
        odd+= 1LL*(n-odd)*odd;
        return odd%mod;
        
    }
};