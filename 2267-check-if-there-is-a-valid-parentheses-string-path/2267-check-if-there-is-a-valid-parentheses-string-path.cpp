class Solution {
public:
bool func(int i,int j,int cnt,vector<vector<char>> &arr,vector<vector<vector<int>>> &dp){
    int n = arr.size();
    int m = arr[0].size();
    // base case
    if(i >= n || j>= m) return false;
     if(arr[i][j] == '(') cnt++;
    else cnt--;
    if(cnt<0) return false;
    if(i==n-1 && j==m-1) {
        
        if(cnt == 0) return true;
        else return false;
    }
    if(dp[i][j][cnt]!=-1) return dp[i][j][cnt];

   

    bool rig = func(i,j+1,cnt,arr,dp);
    bool down = func(i+1,j,cnt,arr,dp);

    return dp[i][j][cnt] = rig || down;
}
    bool hasValidPath(vector<vector<char>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(n+m+1,-1)));

        return func(0,0,0,arr,dp);
        
    }
};