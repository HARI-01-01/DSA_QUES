class Solution {
public:
    int findShortestSubArray(vector<int>& arr) {
        unordered_map<int,int> freq;
        unordered_map<int,int> first;
        unordered_map<int,int> last;

        int n = arr.size();
        int d = 0;
        for(int i=0;i<n;i++){
            int x = arr[i];
            freq[x]++;
            if(first.find(x)==first.end()){
                // not found
                first[x] = i;
            }
            last[x] = i;
            d = max(d,freq[x]);
        }
        int ans = n+1;
        for(auto i:freq){
           
            if(i.second == d){
                ans = min(ans,last[i.first]-first[i.first]+1);
            }
        }
        return ans;
        
    }
};