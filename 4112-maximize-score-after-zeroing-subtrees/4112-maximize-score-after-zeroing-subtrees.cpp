class Solution {
public:
    int dfs(int node,vector<vector<int>>&adj,vector<int> &op,vector<int>&score){
        if(adj[node].size()==0) return score[node];

        int mn = INT_MAX;
        int sum = score[node];

        for(auto i:adj[node]){
            int val = dfs(i,adj,op,score);
            sum+=val;
            mn = min(mn,val);
        }

        if(op[node] || mn<0){
            sum-=mn;
        }
        return sum;
    }
    int maxScore(vector<int>& p, vector<int>& op, vector<int>& score) {
        int n = p.size();
        vector<vector<int>> adj(n);
        for(int i=1;i<n;i++){
            adj[p[i]].push_back(i);
        }

        return dfs(0,adj,op,score);
    }
};