class Solution {
public:
    vector<int> stableMountains(vector<int>& arr, int tar) {
        int n = arr.size();
        vector<int> ans;

        for(int i=1;i<n;i++){
            if(arr[i-1]>tar){
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};