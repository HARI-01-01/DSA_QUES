class Solution {
public:
    bool judgeCircle(string arr) {
        int l = 0,w = 0;
        int n  = arr.size();
        for(int i=0;i<n;i++){
            char ch = arr[i];
            if(ch == 'L') w--;
            else if(ch == 'R') w++;
            else if(ch == 'U') l++;
            else l--;
        }
        return l == 0 && w == 0;
        
    }
};