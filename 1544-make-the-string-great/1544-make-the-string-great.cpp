class Solution {
public:
    string makeGood(string s) {
    int n = s.size();
    bool run = true;
    while(run){
        // cout<<"does this run!"<<endl;
        run = false;
        int n = s.size();
        if(n<2) return s;
        int str = 0,next = 1;
        while(next<n){
            // cout<<"it run !"<<endl;
            if((islower(s[str]) && isupper(s[next]) ||
                isupper(s[str]) && islower(s[next])) &&
                (tolower(s[str]) == tolower(s[next]))){
                run = true;
                s.erase(str,2);
                break;
            }else{
                str++;next++;
            }
        }
        if(!run) break;
    }
    // if (s.empty()) {
    //     cout<<"what the fuck!"<<endl;
    // }
    return s;
}
};