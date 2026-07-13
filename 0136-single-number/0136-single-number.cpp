class Solution {
public:
    int singleNumber(vector<int>& arr) {
        int sum = 0;

        for(auto it:arr){
            sum^=it;
        }
        return sum;
        
    }
};