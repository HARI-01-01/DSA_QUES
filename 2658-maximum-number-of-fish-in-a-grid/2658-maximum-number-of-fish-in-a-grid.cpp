class Solution {
public:
int maxi = 0;
int delr[4]={0,0,1,-1};
int delc[4]={1,-1,0,0};
    int dfs(int r,int c,vector<vector<bool>> &vis,vector<vector<int>>& arr){
        vis[r][c] = true;
        int n =arr.size();
        int m = arr[0].size();
        int sum=arr[r][c];
        for(int i=0;i<4;i++){
            int nr = r+delr[i];
            int nc = c+delc[i];
            if(nr>=0 &&nr<n && nc>=0 && nc<m && arr[nr][nc]!=0){
                if(!vis[nr][nc]){
                    sum+=dfs(nr,nc,vis,arr);
                }
            }
        }
        return sum;
    }
    int findMaxFish(vector<vector<int>>& arr) {
        int n = arr.size();
        int m =arr[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]!=0){
                    if(!vis[i][j]){

                        maxi = max(maxi,dfs(i,j,vis,arr));
                    }
                }
            }
        }
        return maxi;
        
    }
};