class Solution {
public:
    void dfs(int node,vector<int> adj[],vector<bool> &vis) {
    vis[node] = true;
    for (auto it:adj[node]) {
        if (!vis[it]) {
            dfs(it,adj,vis);
        }
    }
   
}
vector<int> remainingMethods(int n, int k, vector<vector<int>>& arr) {
    vector<int> adj[n];
    for(auto it:arr){
        adj[it[0]].push_back(it[1]);
    }
    vector<bool> vis(n,false);
    dfs(k,adj,vis);
    vector<int> ans;

       for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                for(auto x: adj[i])
                {
                    if(vis[x])
                    {
                        vector<int> all;
                        for(int j=0;j<n;j++)
                            all.push_back(j);

                        return all;
                    }
                }
            }
        }
    for(int i=0;i<n;i++){
        if(!vis[i]) ans.push_back(i);
    }
    return ans;



}
};