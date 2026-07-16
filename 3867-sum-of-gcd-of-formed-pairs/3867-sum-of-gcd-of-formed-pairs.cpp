class Solution {
public:
    long long gcdSum(vector<int>& arr) {
        
        int n =arr.size();
        if(n==0) return 0;
        int maxi = arr[0];
        for(int i=0;i<n;i++){
            maxi = max(maxi,arr[i]);
            arr[i]  = gcd(maxi,arr[i]);
        }
        
        sort(arr.begin(),arr.end());
        long long sum = 0;
       int str = 0,end=n-1;
       while(str<end){
        sum += gcd(arr[str],arr[end]);
        str++;
        end--;
       }
        return sum;
        
    }
};