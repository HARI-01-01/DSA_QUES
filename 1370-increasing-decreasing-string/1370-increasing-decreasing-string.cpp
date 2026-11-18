class Solution {
public:
    string sortString(string s) {
        int n = s.size();
        string ans;
        map<char,int> mp;
        for (char c:s) {
            mp[c]++;
        }
    bool turn = true;
    while (true) {
       
        bool run = false;
        string l = "";
        for (auto &i:mp) {
            if (i.second>0) {
                i.second--;
                l+=i.first;
                run = true;
            }
        }

        if (!turn) {
            reverse(l.begin(),l.end());
        }
        turn = !turn;

        if (!run) break;
        ans+=l;
    }
    return ans;
    }

};