class Solution {
public:
    int missingInteger(vector<int>& arr) {
        int n = arr.size();
        int sum = arr[0];
        unordered_map<int,int> mp;
        for(auto i:arr) mp[i]++;
        for(int i=1;i<n;i++){
            if(arr[i]-1 == arr[i-1]){
                sum+=arr[i];
            }else {
                break;
            }
        }
        while(mp.find(sum)!=mp.end()){
            sum++;
        }
        return sum;
    }
};