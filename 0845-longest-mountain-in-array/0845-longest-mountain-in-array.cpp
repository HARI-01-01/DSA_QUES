class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int maxi = 0;
        int i = 1;
        while(i<n){
            int peak = 1;
            while(i<n && arr[i]>arr[i-1]){
                i++;
                peak++;
            }
            if(peak == 1){
                i++;
                continue;
            }
            int down = 1;
            while(i<n && arr[i]<arr[i-1]){
                i++;
                down++;
            }
            if(down == 1){
                i++;
                continue;
            }

            maxi = max(maxi,peak+down - 1);
        }
        return maxi;
        
    }
};