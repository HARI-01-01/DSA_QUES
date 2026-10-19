class Solution {
public:
    vector<int> targetIndices(vector<int>& arr, int tar) {
        int n =arr.size();
        int str = 0;
        int end = n-1;
        int left = -1;
        sort(arr.begin(),arr.end());
        //left most
        while(str<=end){
            int mid = str + (end-str)/2;
            if(arr[mid] == tar){
                left = mid;
                end = mid-1;
            }else if(arr[mid]>tar){
                end = mid - 1;
            }else{
                str = mid+1;
            }
        }
        if(left == -1) return{};
        str = 0,end = n-1;
        int rig = -1;
        //rig side
        while(str<=end){
            int mid = str + (end-str)/2;
            if(arr[mid] == tar){
                rig = mid;
                str = mid+1;
            }else if(arr[mid]>tar){
                end = mid - 1;
            }else{
                str = mid+1;
            }
        }
        if(left == rig){
            return {left};
        }
        vector<int> ans;
        for(int i=left;i<=rig;i++){
            ans.push_back(i);
        }
        return ans;
    }
};