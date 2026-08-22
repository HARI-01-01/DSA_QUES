class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> prev(2,vector<int>(5,0)),curr(2,vector<int>(5,0));

        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int t=0;t<4;t++){
                    int profit;
                    if(buy){
                        profit = max(-arr[i]+prev[!buy][t+1],prev[buy][t]);                
                        }else{
                        profit = max(arr[i]+prev[!buy][t+1],prev[buy][t]);
                        }
                   curr[buy][t] =  profit;
                }
            }
            prev = curr;
        }
        return prev[true][0];
    }
};