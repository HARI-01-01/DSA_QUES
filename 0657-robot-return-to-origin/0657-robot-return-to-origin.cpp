class Solution {
public:
    bool judgeCircle(string arr) {
        int l = 0,w = 0;
        for(char ch : arr){
            if(ch == 'L') w--;
            else if(ch == 'R') w++;
            else if(ch == 'U') l++;
            else l--;
        }
        return l == 0 && w == 0;
        
    }
};