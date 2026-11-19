class Solution {
public:
    int minimizeSum(vector<int>& arr) {
        int n = arr.size();

        sort(arr.begin(),arr.end());

        return min(arr[n-3]-arr[0],min(arr[n-1]-arr[2],arr[n-2]-arr[1]));
        
    }
};