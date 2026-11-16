class Solution {
public:
    string breakString(string s,int k){
    int n = s.size();
    int sum = 0;

    int idx = 0;

    string num;
    while(idx<n){
        sum+=(s[idx]-'0');

        idx++;
        if(idx%k==0){

            num+=to_string(sum);
            // cout<<num<<" : "<<sum<<endl;
            sum = 0;
        }
    }
    if(idx%k!=0){

    num+=to_string(sum);
    }
    return num;
}
string digitSum(string s, int k) {
        int n = s.size();
    if (n<=k) return s;
    while (true) {
        string temp = breakString(s,k);
        s = temp;
        if (s.size()<=k) break;
    }
        return s;
    }
};