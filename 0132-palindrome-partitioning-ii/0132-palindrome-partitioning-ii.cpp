class Solution {
public:
    bool check(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    // int func(int i,string &s,int n,vector<int> &dp){
    //     if(i==n) return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     int mini = 1e9;
    
    //     for(int j=i;j<n;j++){
    //         if(check(i,j,s)){
    //             int cost = 1+func(j+1,s,n,dp);
    //             mini = min(mini,cost);
    //         }
    //     }
    //     return dp[i] =  mini;
    // }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1,0);

        for(int i=n-1;i>=0;i--){
            int mini = 1e9;
    
            for(int j=i;j<n;j++){
                if(check(i,j,s)){
                    int cost = 1+dp[j+1];
                    mini = min(mini,cost);
                }
        }
         dp[i] =  mini;
        }
        return dp[0]-1;
    }
};