class Solution {
public:
    bool stoneGame(vector<int>& arr) {
        int n = arr.size();
        int a = 0, b=0;
        sort(arr.begin(),arr.end());

        for(int i=n-1;i>=0;i--){
            if(i%2==1){
                a+=arr[i];
            }else{
                b+=arr[i];
            }
        }
        return a>b;
        
    }
};