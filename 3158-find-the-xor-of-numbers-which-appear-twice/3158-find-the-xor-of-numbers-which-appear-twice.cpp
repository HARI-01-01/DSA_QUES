class Solution {
public:
    int duplicateNumbersXOR(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;

        sort(arr.begin(),arr.end());

        for(int i=1;i<n;i++){
            if(arr[i]==arr[i-1]) ans^=arr[i];
        }
        return ans;
        
    }
};