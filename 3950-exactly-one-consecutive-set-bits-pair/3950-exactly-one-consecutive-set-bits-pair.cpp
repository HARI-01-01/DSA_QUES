class Solution {
public:
    bool consecutiveSetBits(int n) {

        int last = -1;
        bool run = false;
        for(int i=0;i<32;i++){
            int m = (n&(1<<i))==0?0:1;
            if(m && last==1){
                if(!run){
                    run = true;
                }else{
                    return false;
                }
            }
            last = m;
        }
        return run;
        
    }
};