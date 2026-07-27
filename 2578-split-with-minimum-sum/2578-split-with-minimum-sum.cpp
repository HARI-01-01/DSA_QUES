class Solution {
public:
    int splitNum(int n) {
        vector<int> arr;
        while(n>0){
            arr.push_back(n%10);
            n/=10;
        }
        sort(arr.begin(),arr.end());
        int n1 = 0;
        int n2 = 0;
        int s = arr.size();
        for(int i=0;i<s;i++){
            if(i%2==0){
                //even
                n1 = n1*10  + arr[i];
            }else{
                n2 = n2*10 + arr[i];
            }
        }
        return n1+n2;
        
    }
};