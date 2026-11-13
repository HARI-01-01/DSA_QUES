class Solution {
public:
    bool checkPossibility(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0;

        for(int i=1,err = 0;i<n;i++){
            if(arr[i]<arr[i-1]){
                if(err++|| (i>1 && i<n-1 && arr[i-2]>arr[i] && arr[i+1]<arr[i-1])){
                    return false;
                }
            }
        }

        return true;
        
    }
};