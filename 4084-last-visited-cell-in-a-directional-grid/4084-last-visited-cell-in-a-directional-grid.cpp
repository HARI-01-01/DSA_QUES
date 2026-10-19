class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& arr) {
        int r = arr.size();
        int c = arr[0].size();

        int i = 0,j = 0;
        int li = 0,lj = 0;
        while(i<r && i>=0 && j<c && j>=0 && arr[i][j]!='X'){
            li = i;
            lj = j;
            if(arr[i][j] == 'R'){
                j++;
            }else if(arr[i][j] == 'L') j--;
            else if(arr[i][j]=='U') i--;
            else if(arr[i][j]=='D') i++;
            
            arr[li][lj] = 'X';
        }
        return {li,lj};
        
    }
};