class Solution {
public:
    long long minimumCost(int c1, int c2, int cb, int n1, int n2) {

        long long case1 = 1LL*max(n1,n2) * cb;

        long long case2;
        if(n1 > n2){
            case2 = 1LL*n2*cb + 1LL*(n1-n2)*c1;
        }else{
            case2 = 1LL*n1*cb + 1LL*(n2-n1)*c2;
        }
        long long case3 = 1LL*c1*n1 + 1LL*c2*n2;

        return min(case1,min(case2,case3));
    }
};