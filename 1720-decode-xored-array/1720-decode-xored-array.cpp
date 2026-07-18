class Solution {
public:
    vector<int> decode(vector<int>& arr, int val) {
        int n =arr.size();
        vector<int> ans(n+1);
        ans[0] = val;
        for(int i=0;i<n;i++){
            ans[i+1] = ans[i]^arr[i];
        }
        return ans;
        
    }
};