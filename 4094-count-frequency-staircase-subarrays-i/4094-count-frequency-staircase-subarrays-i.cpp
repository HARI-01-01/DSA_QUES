class Solution {
public:
    int countStaircase(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;

        for(int i=0;i<n;i++){
            int cur = 1;
            int good = 0;
            int sz = 0;
            map<int,int> ord;
            map<int,int> cnt;
            for(int j=i;j<n;j++){
                int x = arr[j];
                int o = ord[x];
                int c = cnt[x]+1;

                if(!o){
                    o = cur;
                    ord[x] = o;
                    cur++;
                    sz++;
                }
                cnt[x] = c;
                if(c==o) good++;
                else if(c>o) break;
                if(good == sz) ans++;
            }
        }
        return ans;
        
    }
};