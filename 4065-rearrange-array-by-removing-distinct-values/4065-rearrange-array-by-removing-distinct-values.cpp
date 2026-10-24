class Solution {
public:
    vector<int> rearrangeArray(vector<int>& arr) {
        vector<int> ans;
        vector<int> mp(101);
        for(int i:arr) mp[i]++;

        while(true){
            bool run = false;
            for(int i=0;i<101;i++){
                if(mp[i]>0){
                    ans.push_back(i);
                    mp[i]--;
                    run = true;
                }
            }
            if(!run) break;
        }
        return ans;


        
    }
};