class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int lmax = 0;
        int rmax = 0;
        int ans = 0;
        int l = 0;
        int r = n-1;

        while(l<r){
            if(arr[l]<=arr[r]){
                // left side
                if(arr[l]<lmax){
                    ans+= lmax - arr[l];
                    // cout<<"left side: "<<lmax-arr[l]<<endl;
                }else {
                    lmax=arr[l];
                }
                l++;
            }else{
                // right side
                if(arr[r]<rmax){
                    ans+= rmax - arr[r];
                    // cout<<"right side: "<<rmax-arr[r]<<endl;
                }else {
                    rmax = arr[r];
                }
                r--;

            }
            // cout<<l<<":"<<r<<endl;
        }
        return ans;

    }
};