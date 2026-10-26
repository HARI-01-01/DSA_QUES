class Solution {
public:
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
void dfs(int i,int j,long long &sum,vector<vector<int>>&vis,vector<vector<int>>&arr){
    int n = arr.size();
    int m = arr[0].size();
    vis[i][j] = 1;
    sum+=arr[i][j];

    for(int k=0;k<4;k++){
        int nr = i+dr[k];
        int nc = j+dc[k];

        if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && arr[nr][nc]!=0){
            dfs(nr,nc,sum,vis,arr);
        }
    }
}
    int countIslands(vector<vector<int>>& arr, int k) {
        int n =arr.size();
        int m = arr[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(!vis[i][j] && arr[i][j]!=0){
                 long long sum = 0;
                dfs(i,j,sum,vis,arr);
                if(sum%k==0) cnt++;
               }
            }
        }
    return cnt;
    }
};