class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();
        for(int i=0;i<n-1;i++){
            arr.push_back(arr[i]);
        }
        int m = arr.size();
        stack<int> st;
        vector<int> ans(m);
        for(int i=m-1;i>=0;i--){
            while(!st.empty() && arr[i]>=st.top()){
                st.pop();
            }
            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();
            st.push(arr[i]);
        }

        while(ans.size()!=n){
            ans.pop_back();
        }
        return ans;
        
    }
};