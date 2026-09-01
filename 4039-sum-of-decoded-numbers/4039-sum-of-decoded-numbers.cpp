class Solution {
public:
    int mod = 1e9 + 7;
    long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

    int sumDecoded(vector<long long>& arr) {
        int n = arr.size();
        long long ans = 0;
        for(auto i:arr){
            vector<int>temp;
            long long tmp = i;
            while(tmp>0){
                temp.push_back(tmp%10);
                tmp/=10;
            }
            reverse(temp.begin(),temp.end());
            int x=0;
            int y=0;
            int w = temp[temp.size()-1];
            for(int i=0;i<w;i++){
                x = x*10 + temp[i];
            }
            for(int i=w;i<temp.size()-1;i++){
                y = y*10+temp[i];
            }
            ans = (ans + power(x,y,mod))%mod;
        }
        return ans;
    }
};