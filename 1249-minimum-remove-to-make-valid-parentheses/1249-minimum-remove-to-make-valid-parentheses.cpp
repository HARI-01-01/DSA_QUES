class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<int> st;
        vector<bool> remove(n,true);
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }else if(s[i] == ')'){
                if(st.empty()){
                    remove[i] = false;
                    continue;
                }else{
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            remove[st.top()] = false;
            st.pop();
        }
        string ans;
        for(int i=0;i<n;i++){
            if(remove[i]){
                ans+=s[i];
            }
        }
        return ans;
    }
};