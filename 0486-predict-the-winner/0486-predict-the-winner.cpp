class Solution {
public:
bool check(int ans, int total){
    return ans>=total-ans;
}
    bool predictTheWinner(vector<int>& arr) {
        int total = 0;
        int n =arr.size();
        for(auto it:arr){
            total+=it;

        }
        
        return check(maxi(arr,total,0,n-1),total);
    }
    int maxi(vector<int>&arr,int total,int i,int j){
        if(i>j) return 0;

        return total - min(maxi(arr,total-arr[i],i+1,j),maxi(arr,total-arr[j],i,j-1));
    }
};