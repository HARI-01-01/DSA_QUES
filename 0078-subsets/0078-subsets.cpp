class Solution {
public:
    vector<vector<int>> subsets(vector<int>& arr) {
        int n =  arr.size();
        int m = 1<<n;

        vector<vector<int>> ans;

        for(int i=0;i<m;i++){
            vector<int> l;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    l.push_back(arr[j]);
                }
            }
            ans.push_back(l);
        }
        return ans;
        
    }
};