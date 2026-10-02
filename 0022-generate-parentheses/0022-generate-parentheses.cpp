class Solution {
public:
    vector<string> ans;

void func(int n,int open,int close,string curr) {
    if (curr.size()  == 2*n) {
        ans.push_back(curr);
        return;
    }
    
    if (open<n) func(n,open+1,close,curr+'(');
    if (close<open) func(n,open,close+1,curr+")");
}
vector<string> generateParenthesis(int n) {
    func(n,0,0,"");
    return ans;
}
};