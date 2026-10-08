class Solution {
public:
void func(int j,int &n,int &k,vector<int> level,vector<vector<int>> &ans){
    int m = level.size();
    // base case
    if(m == k){
        ans.push_back(level);
        return ;
    }

    // all option
    for(int i=j+1;i<=n-k+m+1;i++){
        level.push_back(i);
        func(i,n,k,level,ans);
        level.pop_back();
    }
}
    vector<vector<int>> combine(int n, int k) {
vector<vector<int>> ans;
        

        func(0,n,k,{},ans);
        return ans;
    }
};