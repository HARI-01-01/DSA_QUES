class Solution {
public:
    int minOperations(vector<int>& arr, int x) {
        int n = arr.size();
        int  k =  reduce(arr.begin(),arr.end()) - x;
        if(k<0) return -1;
        if( k == 0) return n;

        int best = -1;
        int l = 0;
        int sum = 0;
        for(int r = 0;r<n;r++){
            sum+=arr[r];
            while(sum>k){
                sum-=arr[l];
                l++;
                
            }
            if(sum == k){
                    best = max(best,r-l+1);
                }
        }
        return best+1?n-best:-1;
        
    }
};