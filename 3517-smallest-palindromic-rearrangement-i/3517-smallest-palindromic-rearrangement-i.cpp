class Solution {
public:
    string smallestPalindrome(string s) {
    int n =s.size();
    map<char,int> mp;
    for(char ch:s) mp[ch]++;
    string ans = "";
   for(auto &it: mp){
           while (it.second>=2) {
                   it.second-=2;
                   ans+= (it.first);
           }
        }
    string mir = ans;
    reverse(mir.begin(),mir.end());
    for(auto &it:mp) {
        if (it.second == 1) {
            ans+=it.first;
        }
    }
    return ans+mir;
}
};