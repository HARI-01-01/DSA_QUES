class Solution {
public:
    string evaluate(string s, vector<vector<string>>& k) {
        int n = s.size();
        string ans;
        unordered_map<string,string>mp;
        for(auto i:k){
            mp[i[0]] = i[1];
        }
        int i = 0;
        while(i<n){
            if(s[i]=='('){
                string find;
                i++;
                while(i<n && s[i]!=')'){
                    find+=s[i];
                    i++;
                }
                i++;
                if(mp.find(find)!=mp.end()){
                    ans+=mp[find];
                }else{
                    ans+="?";
                }
            }else{
                ans+=s[i];
            i++;
            }
            
        }
        return ans;
    }
};