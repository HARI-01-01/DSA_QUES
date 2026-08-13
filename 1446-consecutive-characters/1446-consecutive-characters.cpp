class Solution {
public:
    int maxPower(string s) {
        int n = s.size();
        int cnt = 1;
        int maxi = 1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                cnt++;
            }else{
                maxi = max(maxi,cnt);
                cnt= 1;
            }
        }
        maxi = max(maxi,cnt);
        return maxi;
        
    }
};