class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
        int n =s.size();
        vector<int> ans(n);
        int d = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                d++;
                ans[i] = d%2;
            }else{
                ans[i] = d%2;
                d--;
            }
        }
        return ans;

        
    }
};