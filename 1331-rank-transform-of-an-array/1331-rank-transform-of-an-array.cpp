class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()==0) return {};
        vector<int> val=arr;
        sort(val.begin(),val.end());
        int idx = 1;
        int n =arr.size();
        int last = val[0];
        unordered_map<int,int> mp;
        mp[val[0]] = idx;
        for(int i=1;i<n;i++){
            if(val[i]!=last){
                idx++;
            }
            mp[val[i]] = idx;
            
            last = val[i];   
        }
        for(int i=0;i<n;i++){
            val[i] = mp[arr[i]];
        }
        return val;
    }
};