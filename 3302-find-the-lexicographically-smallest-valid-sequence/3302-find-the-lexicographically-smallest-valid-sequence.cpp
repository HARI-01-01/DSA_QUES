class Solution {
public:
   
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int R = m-1;
        int cnt = 0;
        vector<int>rig(n);
        for(int i=n-1;i>=0;i--){
            rig[i]=cnt;
            if(R>=0 && word1[i]==word2[R]){
                R--;
                cnt++;
            }
        }
        vector<int> ans;
        bool change = false;
        int j=0;
        for(int i=0;i<n&& j<m;i++){
            if(word1[i]==word2[j]){
                ans.push_back(i);
                j++;
            }else if(!change && rig[i]>=m-1-j){
                ans.push_back(i);
                j++;
                change = true;
            }
        }
        if(j==m) return ans;
        return {};
    }
};