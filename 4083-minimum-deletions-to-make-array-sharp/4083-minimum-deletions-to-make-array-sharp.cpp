class Solution {
public:
    int minDeletions(vector<int>& arr) {
        int n = arr.size();
        if(n==2) {
            if(arr[0]==arr[1]){
                return 1;
            }else{
                return 0;
            }
        }
        vector<bool> vis(n,true);
        int str = 0, mid = 1,end = 2;
        while(end<n){
            if(arr[str]==arr[mid] || arr[mid]==arr[end]){
                vis[mid] = false;
                while(!vis[mid]){
                    mid++;
                }
                end = mid+1;
            }else{
                str++;
                while(!vis[str]){
                    str++;
                }
                mid++;
                end++;
            }
        }
        if (arr[str]==arr[end-1]) vis[str] = false;
        int cnt = 0;
        for(auto i:vis){
            if(!i) cnt++;
        }
        return cnt;
    }
};