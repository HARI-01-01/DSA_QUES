class Solution {
public:
    long long maxAlternatingSum(vector<int>& arr) {
        int n = arr.size();
        for(int i=0;i<n;i++){
            arr[i] = abs(arr[i]);
        }
        sort(arr.begin(),arr.end());
    // print_1(arr);
        int m = (n/2-1);
    cout<<"value of m: "<<m<<endl;
        long long sum = 0;
        for(int i=n-1;i>m;i--){
            sum+= (1LL*arr[i]*arr[i]);
            // cout<<"value adding: "<<(1LL*arr[i]*arr[i])<<endl;
        }
        for(int i=m;i>=0;i--){
            sum-= (1LL*arr[i]*arr[i]);
            // cout<<"value sub: "<<(1LL*arr[i]*arr[i])<<endl;

        }
        return sum;

    }
};