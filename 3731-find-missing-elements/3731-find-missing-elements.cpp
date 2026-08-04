class Solution {
public:
    vector<int> findMissingElements(vector<int>& arr) {
       
        int maxi = *max_element(arr.begin(),arr.end());
        int mini = *min_element(arr.begin(),arr.end());
        unordered_map<int,int> mp;
        for(auto i:arr) mp[i];
        vector<int> ans;

        for(int i=mini;i<=maxi;i++){
            if(mp.find(i)==mp.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};