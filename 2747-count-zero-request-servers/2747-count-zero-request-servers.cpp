class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& l, int x, vector<int>& qr) {
        sort(l.begin(),l.end(),[](auto&a,auto &b){
            return a[1]<b[1];
        });

        vector<pair<int,int>> q;

        for(int i=0;i<qr.size();i++){
            q.push_back({qr[i],i});
        }
        sort(q.begin(),q.end());
        vector<int> cnt(n+1), ans(q.size());
        
        int ll = 0,r=0,active =  0;
        for(auto [t,i]:q){
            while(r<l.size() && l[r][1]<=t){
                if(++cnt[l[r++][0]]==1) active++;
            }
            while(ll<r && l[ll][1]<t-x){
                if(--cnt[l[ll++][0]]==0) active--;
            }
            ans[i] = n-active;
        }
        return ans;
    }
};