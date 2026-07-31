class Solution {
public:
    int minimumPushes(string word) {
        vector<int> arr(26,0);
        for(auto ch:word){
            arr[ch-'a']++;
        }
        sort(arr.begin(),arr.end());
        int ans = 0;
        int idx = 1;
        int cnt= 1;
        for(int i=25;i>=0;i--){
            if(arr[i]==0) break;
            if(cnt%9==0){
                cnt=1;
                idx++;
            }
            ans += idx*arr[i];
            cnt++;
        }
        return ans;
        
    }
};