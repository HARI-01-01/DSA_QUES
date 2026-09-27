class Solution {
public:
        string reverseParentheses(string s) {
        int n = s.size();
        stack<char> st;
        int i = 0;
        while(i<n){
            if(s[i]==')'){
                string tmp;
                while(!st.empty() && st.top()!='('){
                    tmp+=st.top();
                    st.pop();
                }
                // reverse(tmp.begin(),tmp.end());
                st.pop();
                for (char c:tmp) {
                    st.push(c);
                }
            }else{
                st.push(s[i]);
            }
            i++;
        }
    string ans;
    while (!st.empty()) {
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;


    }
};