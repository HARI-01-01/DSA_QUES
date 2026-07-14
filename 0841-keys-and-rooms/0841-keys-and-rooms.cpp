class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& arr) {
        int n = arr.size();
        queue<int> q;
        vector<bool> vis(n,false);
        q.push(0);
        
        while(!q.empty()){
            int val = q.front();
            q.pop();
            vis[val]=true;
            for(auto it:arr[val]){
                if(!vis[it]){
                    q.push(it);
                }
            }
        }
        for(auto it:vis){
            if(it==false) return false;
        }
        return true;

        
    }
};