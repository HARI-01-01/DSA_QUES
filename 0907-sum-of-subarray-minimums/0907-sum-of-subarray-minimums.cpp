class Solution {
public:
const int mod = 1e9 + 7;
   int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n),rig(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            left[i] = st.empty()?-1:st.top();
            st.push(i);
        }
    st = stack<int>();
    for (int i=n-1;i>=0;i--) {
        while (!st.empty() && arr[st.top()]>= arr[i])
            st.pop();
        rig[i] = st.empty()?-1:st.top();
        st.push(i);
    }
    // print_1(left);
    // print_1(rig);
    long long ans = 0;
    for (int i=0;i<n;i++) {
        long long l,r;
        if (left[i]!=-1) {
            l = (i-left[i]);
        }else {
            l = (i+1);
        }
        if (rig[i]!=-1) {
            r = (rig[i]-i);
        }else {
            r = (n-i);
        }
        // cout<<l<<":"<<r<<":"<<arr[i]<<endl;
       ans = (ans + (l * r % mod) * arr[i]) % mod;
    }
    return ans;

    }
};