class Solution {
public:
bool func(int n,int k, vector<int> &arr){
    vector<bool> prev(k+1,0),curr(k+1,0);
    prev[0] = curr[0] = true;
   if(arr[0]<=k)  prev[arr[0]] = true;
    for(int i =1;i<n;i++){
        for(int t = 1;t<=k;t++){
            bool notTake = prev[t];
            bool take = false;
            if(arr[i]<= t) take = prev[t-arr[i]];
            curr[t] = take | notTake;
        }
        prev = curr;
    }
    return prev[k];
}
    bool canPartition(vector<int>& arr) {
        int n =arr.size();
        int totalSum = 0;
        for(auto i :arr) totalSum += i;
        if(totalSum%2!=0) return false;
        int tar = totalSum/2;

        return func(n,tar,arr);
        
    }
};