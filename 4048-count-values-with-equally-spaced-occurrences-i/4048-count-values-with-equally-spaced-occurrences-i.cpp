class Solution {
public:
    int countSpecialIntegers(vector<int>& arr) {
        int n = arr.size();

        vector<vector<int>> freq(101);
        for(int i=0;i<n;i++){
            freq[arr[i]].push_back(i);
        }
        int ans = 0;

        for(int i=0;i<101;i++){
            if(freq[i].size() == 3){
                int i1 = freq[i][0];
                int i2 = freq[i][1];
                int i3 = freq[i][2];
                if(i2-i1 == i3-i2) ans++;
            }
        }
        return ans;
        
    }
};