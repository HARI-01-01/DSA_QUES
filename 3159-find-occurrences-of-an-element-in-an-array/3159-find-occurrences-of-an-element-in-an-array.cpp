class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& arr, vector<int>& q, int x) {
        int n = arr.size();
        unordered_map<int,int> mp;
        // idx - x
        int idx = 1;
        for(int i=0;i<n;i++){
            if(arr[i]==x){
                mp[idx] = i;
                idx++;
            }
        }
        int m = q.size();
        vector<int> ans(m,-1);
        for(int i=0;i<m;i++){
            if(mp.find(q[i])!=mp.end()){
                 ans[i] = mp[q[i]];
            }

        }
        return ans;
    }
};