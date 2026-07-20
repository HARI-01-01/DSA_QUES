class Solution {
public:
int ans = 0;
void func(int num){
    vector<int> arr;
    while(num>0){
        arr.push_back(num%10);
        num/=10;
    }
    int n =arr.size();
    if(n<3) return;
    for(int i=1;i<n-1;i++){
        if(arr[i]>arr[i+1]&& arr[i]>arr[i-1]) ans++;
        if(arr[i]<arr[i+1]&& arr[i]<arr[i-1]) ans++;
    }
}
    int totalWaviness(int n1, int n2) {
        for(int i=n1;i<=n2;i++) func(i);
        return ans;
        
    }
};