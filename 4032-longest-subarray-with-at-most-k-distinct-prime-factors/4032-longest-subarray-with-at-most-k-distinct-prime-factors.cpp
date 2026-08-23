class Solution {
public:
unordered_set<int> findPrimeFactors(int n) { 
unordered_set<int> ans;
    // Print the number of 2s that divide n
    while (n % 2 == 0) {
        ans.insert(2);
        n = n / 2;
    }

    // n must be odd at this point. So we can skip one element (Note i = i + 2)
    for (int i = 3; i * i <= n; i = i + 2) {
        while (n % i == 0) {
            ans.insert(i);
            n = n / i;
        }
    }

    // This condition is to handle the case when n is a prime number
    // greater than 2
    if (n > 2) {
        ans.insert(n);
    }
    return ans;
}
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int> st;
        int l = 0;
        int ans = 0;
        for(int r=0;r<n;r++){
            unordered_set<int> temp = findPrimeFactors(arr[r]);
            for(auto i:temp){
                st[i]++;
            }
            while(l<=r && st.size()>k){
                unordered_set<int> temp = findPrimeFactors(arr[l]);
                for(auto i:temp){
                    st[i]--;
                    if(st[i] == 0){
                        st.erase(i);
                    }
                }
                l++;
            }
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};