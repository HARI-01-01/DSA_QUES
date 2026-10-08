class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();

        stack<int> st;
        vector<bool> ans(n,true);
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                st.push(i);
            }else{
                // we have )
                if(st.size() == 1){
                    ans[i] = false;
                    ans[st.top()] = false;
                }
                 st.pop();
            }
        }
        string str = "";
        for(int i=0;i<n;i++){
            if(ans[i]) str+=s[i];
        }

        return str;
    }
};