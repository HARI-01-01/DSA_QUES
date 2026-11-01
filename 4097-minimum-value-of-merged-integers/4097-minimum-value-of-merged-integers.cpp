class Solution {
public:
    int minMergedInteger(vector<int>& arr) {
        int n = arr.size();
        int mini = INT_MAX;
        for(int i=0;i<n-1;i+=2){
            int val = stoi(to_string(arr[i]) + to_string(arr[i+1]));
            mini = min(mini,val);
        }
        return mini;
        
    }
};