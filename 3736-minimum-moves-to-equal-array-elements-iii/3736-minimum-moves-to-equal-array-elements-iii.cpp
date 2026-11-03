class Solution {
public:
    int minMoves(vector<int>& arr) {
        int n = arr.size();
        int maxi = *max_element(arr.begin(),arr.end());
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += abs(arr[i]-maxi);
        }
        return sum;
        
    }
};