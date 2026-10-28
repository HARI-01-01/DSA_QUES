class Solution {
public:
    int firstUniqueEven(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }

        for(int i=0;i<n;i++){
            if((arr[i]&1)==0 && mp[arr[i]]==1){
                return arr[i];
            }
        }
        return -1;
        
    }
};