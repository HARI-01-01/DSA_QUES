class Solution {
public:
    bool sumOfNumberAndReverse(int n) {
        if(n == 0) return true;
        int temp = n;
        for(int i=n;i>=n/2;i--){
            string st = to_string(i);
            reverse(st.begin(),st.end());
            if(i+stoi(st) == n) return true;
        }
        return false;
        
    }
};