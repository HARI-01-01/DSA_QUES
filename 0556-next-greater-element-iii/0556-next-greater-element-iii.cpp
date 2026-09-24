class Solution {
public:
    int nextGreaterElement(int n) {
        if(n<10) return -1;
        vector<int> arr;
        int temp = n;
        while(temp>0){
            arr.push_back(temp%10);
            temp/=10;
        }
        reverse(arr.begin(),arr.end());
        if(!next_permutation(arr.begin(),arr.end())) return -1;
        long sum = 0;
        for(int i:arr){
            sum = sum*10+i;
            if(sum>INT_MAX) return -1;
        }
        return n >= sum?-1:sum;

    }
};