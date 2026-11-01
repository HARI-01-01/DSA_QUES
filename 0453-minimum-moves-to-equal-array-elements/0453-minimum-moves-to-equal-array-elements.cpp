class Solution {
public:
    int minMoves(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0;
        int mn = *min_element(arr.begin(),arr.end());
        for(auto &x : arr){
            cnt+= (x - mn);
        }
        return cnt;
        
    }
};