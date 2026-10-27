class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;

        for(int i=0;i<31;i++){
            int A = (a>>i&1);
            int B = (b>>i&1);
            int C = (c>>i&1);
            
            if(A==0 && B==0){
                if(C==1) cnt++;
            }else if((A==0 && B==1) || (A==1 && B==0)){
                if(C==0) cnt++;
            }else{
                if(C==0) cnt+=2;
            }
        }
        return cnt;
        
    }
};