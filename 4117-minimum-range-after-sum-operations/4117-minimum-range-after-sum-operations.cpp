class Solution {
public:
    int minRange(int a, int b, int c) {
        int val = max(a,max(b,c)) - min(a,min(b,c));

        vector<int> arr(3);
        arr[0] = a;
        arr[1] = b;
        arr[2] = c;

        sort(arr.begin(),arr.end());
        arr[2] = arr[0] + arr[1];
        sort(arr.begin(),arr.end());


        return min(arr[2]-arr[0],val);
    }
};