class Solution {
public:
    bool isBalanced(string arr) {
        int even = 0;
        int odd = 0;
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(i%2==0)even+=(arr[i]-'0');
            else odd+= (arr[i]-'0');
        }
        return even==odd;
    }
};