class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& arr, int k) {
        if(k==0) return arr;
        int r = arr.size();
        int c = arr[0].size();
        vector<vector<int>> temp(r,vector<int>(c));
        while(k>0){
            temp[0][0] = arr[r-1][c-1];
            for(int i=0;i<r;i++){
                for(int j=1;j<c;j++){
                    temp[i][j] = arr[i][j-1];
                }
            }
            for(int i=0;i<r-1;i++){
                temp[i+1][0] = arr[i][c-1];
            }
            arr = temp;
            k--;
        }
        return temp;
    }
};