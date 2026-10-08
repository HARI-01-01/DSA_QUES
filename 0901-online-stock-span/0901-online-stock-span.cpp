class StockSpanner {
public:
stack<pair<int,int>> st;
int cnt = -1;
// val,idx
    StockSpanner() {
        cnt = -1;
       
    }
    
    int next(int val) {
        cnt++;
        while(!st.empty() && st.top().first<=val){
            st.pop();
        }
        int ans = cnt - (st.empty()?-1:st.top().second);
        st.push({val,cnt});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */