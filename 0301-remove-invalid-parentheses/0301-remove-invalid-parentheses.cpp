class Solution {
public:
    bool valid(string s){
        int n = s.size();
        int b = 0;

        for(int i=0;i<n;i++){
            if(s[i] == '(') b++;
            else if(s[i] ==')'){
                b--;
                if(b<0) return false;
            }
        }
        return b == 0;
    }
void func(string s,int n,set<string>& ans,int &mini,unordered_set<string>&vis) {
    if(vis.count(s)) return;
    vis.insert(s);
    int m = s.size();

    if(n-m > mini) return;
    //base case
    if (valid(s)) {
        // it valid
        if (n-m<mini) {
            ans.clear();
            ans.insert(s);
            mini = n -m;
        }else if (n-m == mini) {
            ans.insert(s);
        }
      return;
    }

    //all option

    for (int i=0;i<m;i++) {
        func(s.substr(0,i)+s.substr(i+1),n,ans,mini,vis);
    }
}
vector<string> removeInvalidParentheses(string s) {
    int n = s.size();
    set<string> ans;
    unordered_set<string> vis;
    func(s,n,ans,n,vis);
    return vector<string>(ans.begin(),ans.end());
    
}
};