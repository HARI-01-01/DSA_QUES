class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;

        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;

        for (int i = 0; i < s.size(); i++) {
            char c1 = s[i];
            char c2 = t[i];

            // c1 has been mapped before
            if (mp1.count(c1)) {
                if (mp1[c1] != c2)
                    return false;
            }
            // c2 has been mapped before
            else if (mp2.count(c2)) {
                if (mp2[c2] != c1)
                    return false;
            }
            // Create a new mapping
            else {
                mp1[c1] = c2;
                mp2[c2] = c1;
            }
        }

        return true;
    }
};