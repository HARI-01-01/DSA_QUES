class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& arr) {
        vector<bool> row(m),col(n);
        int cntR = 0,cntC =0;
        for(auto i:arr){
            row[i[0]]=row[i[0]]^true;
            col[i[1]]=col[i[1]]^true;
        }

        for(int i=0;i<m;i++){
            cntR+=row[i]?1:0;
        }
        for(int i=0;i<n;i++){
            cntC+=col[i]?1:0;
        }

        return (m-cntR)*cntC + (n-cntC)*cntR;
    }
};