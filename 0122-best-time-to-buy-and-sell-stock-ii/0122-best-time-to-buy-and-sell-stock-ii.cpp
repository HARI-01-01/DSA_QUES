class Solution {
public:

    int maxProfit(vector<int>& arr) {
        int n = arr.size();
       
       vector<int> prev(2,0),curr(2,0);

        for(int i=n-1;i>=0;i--){
           for(int buy = 0;buy<=1;buy++){
             int profit;
            if(buy){
                profit = max(-arr[i]+prev[!buy],prev[buy]);
            }else{
                profit = max(arr[i]+prev[!buy],prev[buy]);
            }
            curr[buy] = profit;
           }
           prev = curr;
        }
        return prev[true];
        
    }
};