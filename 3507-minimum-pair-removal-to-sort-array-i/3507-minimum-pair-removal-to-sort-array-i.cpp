class Solution {
public:
    int findMinSum(vector<int> &arr){
        int mini = INT_MAX;
        int idx = -1;
        int n = arr.size();

        for(int i=0;i<n-1;i++){
            int sum = arr[i]+arr[i+1];

            if(sum<mini){
                mini = sum;
                idx = i;
            }
        }
        return idx;
    }
    int minimumPairRemoval(vector<int>& arr) {
        int cnt = 0;

        while(!is_sorted(arr.begin(),arr.end())){
            int idx = findMinSum(arr);

            arr[idx] = arr[idx] + arr[idx+1];
            arr.erase(arr.begin()+idx + 1);
            cnt++;
        }
        return cnt;
         
    }
};