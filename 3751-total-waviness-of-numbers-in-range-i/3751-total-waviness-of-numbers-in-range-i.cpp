class Solution {
public:

int func(string arr){
   int cnt = 0;
    
    int n =arr.size();

    for(int i=1;i<n-1;i++){
        if(arr[i]>arr[i+1]&& arr[i]>arr[i-1]) cnt++;
        if(arr[i]<arr[i+1]&& arr[i]<arr[i-1]) cnt++;
    }
    return cnt;
}
    int totalWaviness(int n1, int n2) {
        int ans = 0;
        for(int i=n1;i<=n2;i++){
            string num = to_string(i);
            if(num.size()<3) continue;
            ans+=func(num);
        }
        return ans;
        
    }
};