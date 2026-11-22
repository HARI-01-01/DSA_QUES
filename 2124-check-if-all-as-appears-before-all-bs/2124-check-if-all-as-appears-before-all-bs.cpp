class Solution {
public:
    bool checkString(string s) {
        int n = s.size();

        int cnt = 0;
        for(auto i:s){
            if(i == 'a') cnt++;
        }
        
        int c = 0;
        for(auto i:s){
            if(i == 'a') c++;
            else{
                if(cnt!=c) return false;
                return true;
            }
        }
        return true;
    }
};