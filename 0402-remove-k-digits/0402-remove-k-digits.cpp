class Solution {
public:
    string removeKdigits(string arr, int k) {
        int n = arr.size();
        stack<char> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && st.top()>arr[i]&& k>0){
                k--;
                st.pop();
            }
            st.push(arr[i]);
        }
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        string ans;

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        while(!ans.empty() && ans.back() == '0'){
            ans.pop_back();
        }
        if(ans.size() == 0) return "0";

        reverse(ans.begin(),ans.end());

        return ans;
        
    }
};