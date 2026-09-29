class StockSpanner {
public:

        stack<pair<int,int>> st;
    StockSpanner() {
    }
    
    int next(int val) {
        int cnt = 1;
        while(!st.empty() && st.top().first <= val){
            cnt+= st.top().second;
            st.pop();
        }
        st.push({val,cnt});
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */