class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& arr, int l, int u) {
        int n =arr.size();
        unordered_map<int,int> mp;

        vector<vector<int>> ans;

        for(int i=0;i<n;i++) mp[arr[i]]++;
        int str = l,end = l;
        bool s =false;
        for(int i = l;i<=u;i++){
            if(mp.find(i)==mp.end()){
                // we find the element
                if(!s){
                    str = i;
                    end = i;
                    s = true;
                }else{
                    end = i;
                }
            }else{
                if(s){
                    ans.push_back({str,end});
                    s = false;
                }

            }
        }
        if(s){
                    ans.push_back({str,end});
                    s = false;
                }

        return ans;
    }
};