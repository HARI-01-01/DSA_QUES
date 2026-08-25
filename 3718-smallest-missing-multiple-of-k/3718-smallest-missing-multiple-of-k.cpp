class Solution {
public:
    int missingMultiple(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(auto i:arr) mp[i]++;
        int idx = 1;
        while(true){
            if(mp.find(k*idx)==mp.end()){
                // not find
                break;
            }
            idx++;
        }
        return k*idx;
        
    }
};