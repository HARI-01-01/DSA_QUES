class Solution {
public:
    int findGCD(vector<int>& arr) {
    sort(arr.begin(),arr.end());

    return gcd(arr[0],arr[arr.size()-1]);
        
    }
};