class Solution {
public:
    int findUnsortedSubarray(vector<int>& arr) {
        int n =arr.size();
        int l = -1,r = -1;
        int maxSeem = arr[0], minSeem = arr[n-1];

        for(int i=1;i<n;i++){
            maxSeem = max(maxSeem,arr[i]);
            if(maxSeem > arr[i]){
                r= i;
            }
        }
        for(int i=n-2;i>=0;i--){
            minSeem = min(minSeem,arr[i]);
            if(minSeem < arr[i]){
                l= i;
            }
        }
        if(r == -1) return 0;
        return r-l+1;

        
    }
};