class Solution {
public:
    int furthestDistanceFromOrigin(string s) {
        int l = 0,r = 0;
        int n = s.size();
        for(char ch:s){
            if(ch == 'L') l++;
            else if(ch == 'R') r++;
        }
        int ans = r-l;
        if(r>=l){
            return abs(ans+(n-r-l));
        }
        return abs(ans-(n-r-l));
    }
};