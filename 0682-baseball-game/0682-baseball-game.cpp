class Solution {
public:
    int calPoints(vector<string>& arr) {
        int n = arr.size();
        vector<int> vis;
        for(auto i:arr){
            if(i == "C" && vis.size()>0){
                vis.pop_back();
            }else if(i == "D" && vis.size()>0){
                vis.push_back(vis[vis.size()-1]*2);
            }else if(i == "+" && vis.size()>1){
                vis.push_back(vis[vis.size()-1] + vis[vis.size()-2]);
            }else{
                vis.push_back(stoi(i));
            }
        }
        int sum = 0;
        for(auto i:vis) sum+= i;
        return sum;
        
    }
};