class Solution {
public:
    int maxLength(vector<int>& arr) {
        int n = arr.size();

        int l = 0;
        int best = 2;
        int pro = 1;

        for(int r=0;r<n;r++){
            int x = arr[r];
            while(gcd(pro,x)>1){
                pro/=arr[l++];
            }
            pro*=x;
            best = max(best,r-l+1);
        }
        return best;
        
    }
};