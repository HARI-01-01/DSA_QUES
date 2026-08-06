class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    int fir = abs(arr[i]-arr[j]);
                    int sec = abs(arr[j]-arr[k]);
                    int thr = abs(arr[k]-arr[i]);

                    if(fir<=a && sec <=b && thr <= c){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};