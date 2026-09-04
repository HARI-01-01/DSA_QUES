class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans = "";
        int idx = 0;
        int n = s.size();
        while(idx<n && k>0){
            if(s[idx]==' '){
                ans+=' ';
                k--;
            }else{
                ans+= s[idx];
            }
            idx++;
        }
        if(ans[ans.size()-1]==' ') ans.pop_back();
        return ans;
    }
};