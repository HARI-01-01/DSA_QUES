class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size();
        int cnt= n;

        for(int i=0;i<n;i++){
            for(int j:arr2){
                if(abs(arr1[i]-j)<=d){
                    cnt--;
                    break;
                }
            }
        }
        return cnt;
        
    }
};