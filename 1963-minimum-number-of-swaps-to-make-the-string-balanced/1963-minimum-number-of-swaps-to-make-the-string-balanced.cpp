class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int str = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '['){
                str = i;
                break;
            }
        }
        int bal = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '[') bal++;
            else bal--;
            if(bal<0){
                ans++;
                while(s[str]!='['){
                    str++;
                }
                bal+=2;
            }
        }
        return ans;
    }
};