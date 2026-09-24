class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& arr1, vector<int>& arr2) {
        int n = arr2.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr2[i]] = i;
        }

        vector<int> next(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr2[i]>st.top()){
                st.pop();
            }
            if(st.empty()) next[i] = -1;
            else next[i] = st.top();
            st.push(arr2[i]);
        }
        int m = arr1.size();
        vector<int> ans(m);
        for(int i=0;i<m;i++){
            ans[i] = next[mp[arr1[i]]];
        }
        return ans;
    }
};