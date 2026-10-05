class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        // idx
        stack<int> st;
        int ans = -1;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                int val = arr[st.top()];
                st.pop();
                int pse = !st.empty()?st.top():-1;
                ans = max(ans, val*(i-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
                int val = arr[st.top()];
                st.pop();
                int pse = !st.empty()?st.top():-1;
                ans = max(ans, val*(n-pse-1));
        }
        return ans;
        
    }
};