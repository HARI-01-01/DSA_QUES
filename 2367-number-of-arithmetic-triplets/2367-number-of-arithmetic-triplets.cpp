class Solution {
public:
    int arithmeticTriplets(vector<int>& arr, int d) {
        int n = arr.size();

        unordered_map<int,int> mp;
        // val, idx

        for(int i=0;i<n;i++){
            mp[arr[i]] = i;
        }

        int cnt = 0;

        for(int j=1;j<n-1;j++){
            int iv = arr[j] - d;
            int kv = arr[j] + d;

            if(mp.find(iv)!=mp.end() && mp.find(kv)!=mp.end()){
                int i = mp[iv];
                int k = mp[kv];

                if(i<j && j<k) cnt++;
            } 
        }
        return cnt;
        
    }
};