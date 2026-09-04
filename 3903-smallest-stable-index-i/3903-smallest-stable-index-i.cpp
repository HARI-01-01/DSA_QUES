class Solution {
public:
    int firstStableIndex(vector<int>& arr, int k) {
    int n =arr.size();
    int maxi = INT_MIN;
    int mini = INT_MAX;
    for (int i=0;i<n;i++) {
        maxi = max(maxi,arr[i]);
               mini = *min_element(arr.begin()+i,arr.end());

        int val = maxi - mini;
        if (val <= k) {
            return i;
        }
    }
    return -1;
        
}
};