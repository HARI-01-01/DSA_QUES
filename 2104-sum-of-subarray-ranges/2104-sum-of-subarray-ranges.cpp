class Solution {
public:
long long mini(vector<int> &arr){
    int n = arr.size();
    vector<int> left(n),rig(n);

    stack<int> st;

    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>arr[i]){
            st.pop();
        }
        left[i] = st.empty()?-1:st.top();
        st.push(i);
    }

    st = stack<int>();

    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        rig[i] = st.empty()?-1:st.top();
        st.push(i);
    }
    // print_1(left);
    // print_1(rig);
    long long ans = 0;
    for(int i=0;i<n;i++){
        int l = left[i]!=-1?i-left[i]:i+1;
        int r = rig[i]!=-1?rig[i]-i:n-i;

        ans += 1LL*l*r*arr[i];
    }
    // cout<<ans<<endl;
    return ans;
}
long long maxi(vector<int> &arr){
    int n = arr.size();
    vector<int> left(n),rig(n);

    stack<int> st;

    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]<arr[i]){
            st.pop();
        }
        left[i] = st.empty()?-1:st.top();
        st.push(i);
    }


    st = stack<int>();

    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]<=arr[i]){
            st.pop();
        }
        rig[i] = st.empty()?-1:st.top();
        st.push(i);
    }

    long long ans = 0;
    for(int i=0;i<n;i++){
        int l = left[i]!=-1?i-left[i]:i+1;
        int r = rig[i]!=-1?rig[i]-i:n-i;

        ans += 1LL*l*r*arr[i];
    }
    return ans;
}
long long subArrayRanges(vector<int>& arr) {
        return maxi(arr) - mini(arr);
}
};