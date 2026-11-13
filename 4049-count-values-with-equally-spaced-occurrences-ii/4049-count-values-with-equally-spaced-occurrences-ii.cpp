class Solution {
public:
    int countSpecialIntegers(vector<int>& arr) {
        int n = arr.size();
        

        unordered_map<int,vector<int>> freq;
        for(int i=0;i<n;i++){
            freq[arr[i]].push_back(i);
        }
        int ans = 0;

        for(auto [i,it]:freq){
            if(freq[i].size() > 2){
                int i1 = freq[i][0];
                int i2 = freq[i][1];
               int val = i2-i1;
               int m = freq[i].size();
               int run = false;
                for(int j=2;j<m;j++){
                    if(freq[i][j]-freq[i][j-1] != val){
                        run = true;
                        break;
                    }
                }
                if(!run) ans++;
            }
        }
        return ans;
        
    }
};