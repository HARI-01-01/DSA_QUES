class Solution {
public:
    int mostFrequent(vector<int>& arr, int k) {
        int n =arr.size();
        unordered_map<int,int> mp;
        for(int i=0;i+1<n;i++){
            if(arr[i]==k){
                mp[arr[i+1]]++;
            }
        }
        int ans = -1;
        int maxi = 0;
        for(auto [x,f]:mp){
            if(f>maxi){
                maxi = f;
                ans = x;
            }
        }
        return ans;
        
    }
};