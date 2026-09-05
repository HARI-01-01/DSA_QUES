class Solution {
public:
     int firstStableIndex(vector<int>& arr, int k) {
    int n =arr.size();
    int maxi = INT_MIN;
    vector<int> mini(n,-1);
    int m = INT_MAX;
    for (int i=n-1;i>=0;i--) {
        if (arr[i]<m) {
            m = arr[i];
        }
        mini[i] = m;
    }
    for (int i=0;i<n;i++) {
        maxi = max(maxi,arr[i]);
        int val = maxi - mini[i];
        if (val <= k) {
            return i;
        }
    }
    return -1;
     }
};