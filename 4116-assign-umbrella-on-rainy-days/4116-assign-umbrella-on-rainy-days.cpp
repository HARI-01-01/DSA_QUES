class Solution {
public:
    vector<string> assignUmbrella(vector<int>& arr) {
        int n = arr.size();
        vector<string> ans(n);

        int alice = 0;
        int bob = 0;

        for(int i=0;i<n;i++){
            if(i<n-1&&arr[i] == 1 && arr[i+1] == 1){
                if(alice>bob){
                    bob++;
                    ans[i] = "Bob";
                }else {
                    alice++;
                    ans[i] = "Alice";
                }
            }else if(arr[i] == 1){
                bob++;
                ans[i] = "Bob";
            }else if(arr[i] == 0){
                ans[i] = "None";
            }
        }
        return ans;
        
    }
};