class Solution {
public:
int reverseNumber (int x) {
        int rev = 0; 

        while ( x > 0 ) {
            int ld = x % 10;
            rev = (rev*10) + ld;

            x = x/10;
        } 

        return rev;
    }
    bool sumOfNumberAndReverse(int n) {
        if(n == 0) return true;
        int temp = n;
        for(int i=n;i>=n/2;i--){
           int rev = reverseNumber(i);
            if(i+rev == n) return true;
        }
        return false;
        
    }
};