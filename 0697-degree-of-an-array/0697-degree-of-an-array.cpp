class Solution {
public:
  int findShortestSubArray(vector<int>& arr) {
    int n =arr.size();
    vector<int> vis(50000,0);
    int cnt = 0;

    for(int i=0;i<n;i++){
        vis[arr[i]]++;
        cnt = max(cnt,vis[arr[i]]);
    }
    vector<int> freq;
    for (int i=0;i<50000;i++) {
        if (vis[i]==cnt) {
            freq.push_back(i);
        }
    }

    int ans = n+1;
    int m = freq.size();
for (int j=0;j<m;j++) {
    int str = -1;
    int end = -1;
    for(int i=0;i<n;i++){
        if(freq[j]==arr[i]){
            if(str==-1){
                str = i;
            }else{
                end = i;
            }
        }
    }
    if (end == -1) ans = min(ans,1);
    else {
        ans = min(ans,end-str+1);
    }
}
  return ans;

}
};