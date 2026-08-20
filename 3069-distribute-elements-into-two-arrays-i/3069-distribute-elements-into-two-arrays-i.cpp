class Solution {
public:
    vector<int> resultArray(vector<int>& arr) {
        int n = arr.size();
        vector<bool> vis(n,false);
        vis[0] = true;
        int i=0,j=1;
        while(j!=n-1){
            if(arr[i]>arr[j]){
                int temp = j;
                j++;
                vis[j] = vis[i];
                i=temp;
            }else{
                int temp = j;
                j++;
                vis[j] = vis[temp];
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(vis[i]){
                ans.push_back(arr[i]);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};