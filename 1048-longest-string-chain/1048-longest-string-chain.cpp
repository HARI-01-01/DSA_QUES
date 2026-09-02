class Solution {
public:
 bool compare(string &f,string &s){
    if(f.size()+1 != s.size()) return false;

    int fir = 0, sec = 0;
    while(sec < s.size()){
        if(fir<f.size() && f[fir] == s[sec]){
            fir++;
            sec++;
        }else{
            sec++;
        }
    }
    return fir==f.size() && sec == s.size();
}
    int longestStrChain(vector<string>& arr) {
        int n = arr.size();
        vector<int> dp(n,1);
      sort(arr.begin(), arr.end(), [](const auto &a, const auto &b) {
    return a.size() < b.size();
});
        int maxi = 1;
        for (int i=1;i<n;i++) {
            for (int j=i-1;j>=0;j--) {
                if (compare(arr[j],arr[i]) && dp[i]<dp[j]+1) {
                    dp[i] = dp[j]+1;
                }
            }
            maxi = max(maxi,dp[i]);
        }
        // print_1(dp);
        return maxi;
    }
};