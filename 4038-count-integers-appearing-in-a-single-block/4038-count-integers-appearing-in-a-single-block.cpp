class Solution {
public:
    int countSpecialIntegers(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        for(auto i:arr) mp[i]++;
        int ans = 0;
        int l = 0;
        for(int i=1;i<n;i++){
            if(arr[l]!=arr[i]){
                if(mp[arr[l]] == (i-l)) ans++;
                l = i;
            }
        }
        if(mp[arr[l]] == (n-l)) ans++;
        return ans;
    }
};