class Solution {
public:
vector<vector<int>> ans;
void func(int j,int &n,int &k,vector<int> level){
    // base case
    if(level.size() == k){
        ans.push_back(level);
        return ;
    }

    // all option
    for(int i=j+1;i<=n;i++){
        level.push_back(i);
        func(i,n,k,level);
        level.pop_back();
    }
}
    vector<vector<int>> combine(int n, int k) {
        

        func(0,n,k,{});
        return ans;
    }
};