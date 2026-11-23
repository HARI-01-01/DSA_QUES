class ProductOfNumbers {
public:

        vector<int> dp;
    ProductOfNumbers() {
        dp.clear();
    }
    
    void add(int num) {
        int n = dp.size();
        for(int i=0;i<n;i++){
            dp[i]*=num;
        }
        dp.push_back(num);
    }
    
    int getProduct(int k) {
        
        return dp[dp.size()-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */