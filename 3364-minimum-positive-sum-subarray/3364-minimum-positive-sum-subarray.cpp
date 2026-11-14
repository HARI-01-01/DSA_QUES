class Solution {
public:
    int minimumSumSubarray(vector<int>& arr, int l, int r) {
        int n = arr.size();
        int mini = INT_MAX;

        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum+=arr[j];
                if(j-i+1>= l && j-i+1<=r){
                    if(sum>0){
                        mini = min(mini,sum);
                    }
                }
                if(j-i+1>r) break;
            }
        }
        return mini==INT_MAX?-1:mini;
        
    }
};