class Solution {
public:
    int helper(string s,int k){
        if(s.size()<k) return 0;

        unordered_map<char,int> mp;
        for(auto i:s) mp[i]++;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(mp[s[i]]<k){
                int left = helper(s.substr(0,i),k);
                int rig = helper(s.substr(i+1),k);

                return max(left,rig);
            }
        }
        return s.size();
    }
    int longestSubstring(string s, int k) {

        return helper(s,k);
        
    }
};