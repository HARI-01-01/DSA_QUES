class Solution {
public:
    int sortPermutation(vector<int>& arr) {
        int n = arr.size();
        int ans = INT_MAX;
        for(int i=0;i<n;i++) {
            if(arr[i] != i) ans&=i;
        }
        return ans == INT_MAX?0:ans;
        
    }
};