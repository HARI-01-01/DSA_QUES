class Solution {
public:
int func(vector<int>& arr) {
    int n = arr.size();
    stack<int> st;
    vector<int> left(n,0);
    int i=0;
    while (i<n) {
        if (st.empty()) {
            left[i] = i;
        }else {
            while (!st.empty() && arr[st.top()]>= arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                left[i] = 0;
            }else {
                left[i] = st.top()+1;
            }
        }
        st.push(i);
        i++;
    }
    vector<int> rig(n,0);
    int j = n-1;
    st = stack<int>();
    while (j>=0) {
        if (st.empty()) {
            rig[j] = j;
        }else {
            while (!st.empty() && arr[st.top()]>=arr[j]) {
                st.pop();
            }
            if (st.empty()) {
                rig[j] = n-1;
            }else {
                rig[j] = st.top()-1;
            }
        }
        st.push(j);
        j--;
    }
    // print_1(left);
    // print_1(rig);

    int ans = 0;
    for (int i=0;i<n;i++) {
        ans = max(ans,(rig[i]-left[i]+1)*arr[i]);
    }
    return ans;
    }
    int maximalRectangle(vector<vector<char>>& arr) {
        if(arr.empty()) return 0;
        int r = arr.size();
        int c = arr[0].size();
        int ans =0;
        vector<int> level(c,0);

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(arr[i][j]=='0'){
                    level[j] = 0;
                }else{
                    level[j]++;
                }
            }
            ans = max(ans,func(level));
        }
        return ans;
        
    }
};