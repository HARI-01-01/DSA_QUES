class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            char c = s[i];
            // cout<<26-(c-'a')<<endl;
            ans+= (i+1)*(26-(c-'a'));
        }
        return ans;
    }
};