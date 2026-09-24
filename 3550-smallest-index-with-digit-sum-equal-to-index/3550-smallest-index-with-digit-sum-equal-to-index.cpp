class Solution {
public:
    int smallestIndex(vector<int>& arr) {
        int n = arr.size();
        int ans = -1;
        for(int i=0;i<n;i++){
            int dig = arr[i];
            int sum = 0;
            while(dig>0){
                sum+= dig%10;
                dig/=10;
            }
            if(sum==i){
                ans = i;
                break;
            }
        }
        return ans;
        
    }
};