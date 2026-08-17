class Solution {
public:
int ans = 0;
   void func(int idx,vector<int>&arr){
    // base case
    if(idx<0) return;
    if(idx==0) {
        ans = arr[idx];
        return;
    }
    int n = arr.size();
    if(n>1){
        int val = arr[idx] - arr[idx-1];

        if(val>0){
           int in = -1;
            for(int i=0;i<idx-1;i++){
                if (arr[i]>val){
                    in = i;
                    break;
                }
            }
            arr.pop_back();
            arr.pop_back();
            if (in!=-1) {
                arr.insert(arr.begin()+in,val);
            }else {
                arr.push_back(val);
            }


            // print_1(arr);
            func(arr.size()-1,arr);
        }else{
            arr.pop_back();
            arr.pop_back();
            // print_1(arr);
            func(arr.size()-1,arr);
        }
    }
}
int lastStoneWeight(vector<int>& arr) {
    int n =arr.size();
    sort(arr.begin(),arr.end());

    func(n-1,arr);
    return ans;

}
};