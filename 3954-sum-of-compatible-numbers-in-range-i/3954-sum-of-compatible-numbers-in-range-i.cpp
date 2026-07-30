class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int str = n-k;
        int end = n+k;
        int ans = 0;
        if(str<0) str = 1;
        for(int i=str;i<=end;i++){
            if((n&i)==0) ans+=i;
        }
        return ans;
        
    }
};