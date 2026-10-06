class Solution {
public:
    int func(vector<int> &arr){
        int n = arr.size();
        // idx
        stack<int> st;
        int ans = -1;

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]> arr[i]){
                int val = st.top();st.pop();
                int pse = st.empty() ? -1:st.top();
                ans = max(ans,arr[val]*(i-pse-1));
            }
            st.push(i);
        }

        while(!st.empty()){
            int val = st.top();st.pop();
            int pse = st.empty() ? -1:st.top();
            ans = max(ans,arr[val]*(n-pse-1));
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& arr) {
        int n = arr.size();
        int m =arr[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(arr[0][i] == '1') vis[0][i] = 1;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j] == '1'){
                    vis[i][j] = vis[i-1][j] + 1;
                }
            }
        }
        int maxi = -1;

        for(int i=0;i<n;i++){
            maxi = max(maxi,func(vis[i]));
        }
        return maxi;


    }   
};