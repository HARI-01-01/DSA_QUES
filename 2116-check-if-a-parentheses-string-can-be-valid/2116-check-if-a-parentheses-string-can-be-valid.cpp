class Solution {
public:
    bool canBeValid(string s, string l) {
        int n = s.size();
        if(n%2==1) return false;

        int minBalance = 0, maxBalance = 0;

        for(int i=0;i<n;i++){
            if(l[i] == '1'){
                // locked
                if(s[i] == '('){
                    minBalance++;
                    maxBalance++;
                }else{
                    minBalance--;
                    maxBalance--;
                }
            }else{
                minBalance--;
                maxBalance++;
            }

            if(maxBalance < 0) return false;

            minBalance = max(0,minBalance);
        }
        return minBalance == 0;
    }
};