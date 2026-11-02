class Solution {
public:
    int minMoves2(vector<int>& arr) {
        int n =arr.size();
        int idx = n/2;
        int cnt = 0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            cnt += abs(arr[idx] - arr[i]);
        }
        return cnt;
        
    }
};