class Solution {
public:
    int smallestNumber(int n) {
        int tmp = n;
        
        int idx = 1;
        while(tmp>0){
            if(tmp%2==0) n+= idx;
            tmp/=2;
            idx*=2;
        }
        return n;
        
    }
};