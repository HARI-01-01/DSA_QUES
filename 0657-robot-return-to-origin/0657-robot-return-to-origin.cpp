class Solution {
public:
    bool judgeCircle(string arr) {
        int l = 0,w = 0;
        int n  = arr.size();
        for(int i=0;i<n;i++){
            
            if(arr[i] == 'L') w--;
            else if(arr[i] == 'R') w++;
            else if(arr[i] == 'U') l++;
            else l--;
        }
        return l == 0 && w == 0;
        
    }
};