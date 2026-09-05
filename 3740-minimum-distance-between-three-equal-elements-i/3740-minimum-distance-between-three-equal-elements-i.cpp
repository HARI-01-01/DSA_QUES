class Solution {
public:
    int minimumDistance(vector<int>& arr) {
        int n =  arr.size();
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(arr[i]==arr[j]&&arr[j]==arr[k]){
                        mini = min(mini,abs(i-j)+abs(j-k)+abs(k-i));
                    }
                }
            }
        }
        return mini==INT_MAX?-1:mini;
        
    }
};