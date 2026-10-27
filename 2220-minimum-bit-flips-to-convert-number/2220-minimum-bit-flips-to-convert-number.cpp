class Solution {
public:
    int minBitFlips(int str, int k) {
        int ans = str ^ k;

        int cnt = 0;
        for(int i=0;i<31;i++){
            if(ans & (1<<i)) cnt++;
        }
        return cnt;
        
    }
};