class Solution {
public:
    int numberOfSteps(int num) {
        int cnt = 0;
        while(num>0){
            if(num&1){
                // odd
                num--;
            }else{
                //even
                num/=2;
            }
            cnt++;
        }
        return cnt;
    }
};