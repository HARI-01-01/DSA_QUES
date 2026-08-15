class Solution {
public:
    int longestSubsequence(vector<int>& arr) {
        int t = 0,len = arr.size();
        bool non = false;
        for(auto i:arr){
            non |= i>0;
            t^=i;
        }
        if(t!=0) return len;
        if(non) return len -1;
        return 0;
        
    }
};