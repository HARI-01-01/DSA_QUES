class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& arr, vector<int>& q, int x) {
        int n = arr.size();
        vector<int> pos;
        // idx - x
        int idx = 1;
        for(int i=0;i<n;i++){
            if(arr[i]==x){
                pos.push_back(i);
            }
        }
        int m = q.size();
        vector<int> ans(m,-1);
        for(int i=0;i<m;i++){
            if(q[i]-1<pos.size()){
                ans[i] = pos[q[i]-1];
            }

        }
        return ans;
    }
};