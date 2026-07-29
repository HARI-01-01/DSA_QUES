class Solution {
public:
    int maxRepeating(string sq, string word) {
        int idx = 0;
        string look = word;
        while(true){
            size_t pos = sq.find(look);
            if(pos!= string::npos){
                idx++;
                look+=word;
            }else{
                break;
            }

        }
        return idx;

    }
};