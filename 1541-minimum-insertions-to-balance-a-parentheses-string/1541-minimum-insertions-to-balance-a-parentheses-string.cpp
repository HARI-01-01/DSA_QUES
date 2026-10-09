class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        stack<int> st;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                if(!st.empty()){
                    if(st.top() == 1){
                        cnt++;
                        st.pop();
                        
                    }
                }
                st.push(0);
            }else{
                // )
                if(st.empty()){
                    st.push(1);
                    cnt++;
                }else{
                    if(st.top() == 0){
                        // 0->1
                        st.top()++;
                    }else if(st.top() == 1){
                        st.pop();
                    }
                }
            }
        }
        while(!st.empty()){
            cnt += (2-st.top());
            st.pop();
        }
        return cnt;
        
    }
};