class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int idx = 1;
        int ans = 0;
        while(n>8){
            ans += idx * 8;
            n-=8;
            idx++;
        }
        ans += idx * n;
        return ans;
        
    }
};