class Solution {
public:
    long long minSumSquareDiff(vector<int>& arr, vector<int>& brr, int k1, int k2) {
        int n = arr.size();
        vector<int> diff(n);
        int maxi = 0;
        for(int i=0;i<n;i++){
            int x = abs(arr[i]-brr[i]);
            diff[i] = x;
            maxi = max(maxi,x);
        }
        long long k = k1+k2;
        vector<int> freq(maxi+1);
        for(int i:diff){
            freq[i]++;
        }
        for(int i=maxi;i>0 && k>0 ;i--){
            int take = min((long long) freq[i],k);
            freq[i] -= take;
            freq[i-1]+= take;
            k-=take;
        }

        long long ans = 0;
        for(int i=1;i<=maxi;i++){
            ans += 1LL*freq[i]*i*i;
        }
        return ans;
        
    }
};