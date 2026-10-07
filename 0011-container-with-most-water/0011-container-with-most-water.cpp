class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n = arr.size();
        int str = 0,end = n-1;
        int maxi=-1;
        while(str<end){
            maxi = max(maxi,min(arr[str],arr[end])*(end-str));
            if(arr[str]>arr[end]){
                end--;
            }else{
                str++;
            }
        }
        return maxi;
        
    }
};