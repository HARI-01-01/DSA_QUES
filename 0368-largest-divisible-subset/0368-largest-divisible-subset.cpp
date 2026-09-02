class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();
    sort(arr.begin(),arr.end());
    vector<int> dp(n,1);
    vector<int> hash(n);
    int lastIdx = 0;
    int maxi = 1;
    for(int i=1;i<n;i++){
        hash[i] = i;
        for(int j=i-1;j>=0;j--){
            if(arr[i]%arr[j]==0 && dp[i]<dp[j]+1){
                dp[i] = dp[j] + 1;
                hash[i] = j;
            }
        }
        if (dp[i]>maxi) {
            maxi = dp[i];
            lastIdx = i;
        }
    }
    // print_1(arr);
    // print_1(dp);
    // print_1(hash);
    // cout<<lastIdx<<" "<<maxi<<endl;
    vector<int> temp;
    temp.push_back(arr[lastIdx]);
    while (hash[lastIdx]!=lastIdx) {
        lastIdx = hash[lastIdx];
        temp.push_back(arr[lastIdx]);
    }

// print_1(temp);
        return temp;

    }
};