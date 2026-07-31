class Solution {
public:
    int countDigitOccurrences(vector<int>& arr, int k) {
        int n = arr.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            int dig = arr[i];
            while(dig>0){
                if(dig%10==k){
                    cnt++;
                }
                dig/=10;
            }
        }
        return cnt;
        
    }
};