class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n =nums.size();
        vector<int> arr(nums.begin(),nums.end());
        sort(arr.begin(),arr.end());
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            if(i==0){
                mp[arr[i]] = i;
            }else{
                if(arr[i-1]==arr[i]){
                    mp[arr[i]] = mp[arr[i-1]];
                }else{
                    mp[arr[i]] = i;
                }
            }
        }
        vector<int> ans(n);

        for(int i=0;i<n;i++){
            ans[i] = mp[nums[i]];
        }
        return ans;




        
    }
};