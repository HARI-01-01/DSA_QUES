class Solution {
public:
    bool checkDivisibility(int n) {
        int pro = 1;
        int sum = 0;
        int temp = n;
        while(n>0){
            pro*=n%10;
            sum += n%10;
            n/=10;
        }
        return (temp%(pro+sum)==0);
    }
};