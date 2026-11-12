class Solution {
public:
    int longestMonotonicSubarray(vector<int>& arr) {
        int n = arr.size();

        int maxI = 0;
        int prev = arr[0];
        int cnt = 1;
        for(int i=1;i<n;i++){
            if(arr[i]>prev){
                cnt++;
            }else{
                maxI = max(maxI,cnt);
                cnt = 1;
            }
            prev = arr[i];
        }
        maxI = max(maxI,cnt);
        int maxD = 0;
        prev = arr[0];
        cnt = 1;
         for(int i=1;i<n;i++){
            if(arr[i]<prev){
                cnt++;
            }else{
                maxD = max(maxD,cnt);
                cnt = 1;
            }
            prev = arr[i];
        }
        maxD = max(maxD,cnt);
        return max(maxI,maxD);
        
    }
};