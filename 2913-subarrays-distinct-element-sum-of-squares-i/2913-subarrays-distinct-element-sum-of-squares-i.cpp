class Solution {
public:
    int sumCounts(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            set<int> st;
            for(int j=i;j<n;j++){
                st.insert(arr[j]);
                ans += pow(st.size(),2);
            }
           
        }
        return ans;
    }
};