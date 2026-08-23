class Solution {
public:
    bool isPalindromic(string s) {
        string bin = "";

        for(auto i:s){
            int dig = (int)i;
            string add = "";
            while(dig>0){
                add+=to_string(dig%2);
                dig/=2;
            }
            reverse(add.begin(),add.end());
            while(add.size()<8){
                add.insert(0,1,'0');
            }
            bin+=add;

        }
        int str = 0;
        int end = bin.size()-1;
        while(str<=end){
            if(bin[str]!=bin[end]){
                return false;
            }
            str++;
            end--;
        }
        return true;
    }
};