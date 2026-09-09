class Solution {
public:
    long long countCommas(long long n) {
    if(n<1000) return 0;
    long long ans = 0;

    int cnt = 0;
    // counting the number of digit
    long long tmp = n;
    while(tmp>0){
        tmp/=10;
        cnt++;
    }
    cnt--;
    // cout<<cnt<<endl;
    long long num = 0;
    // while (cnt>0) {
    //     num = num*10 + 9;
    //     cnt--;
    // }
    for (int i=0;i<cnt;i++) {
        num=num*10+9;
    }
    while (num>=999) {
        ans += (n-num)*(cnt/3);
        // cout<<(n-num)<<" : "<<(cnt/3)<<"=="<<(n-num)*(cnt/3)<<endl;
        n = num;
        num/=10;
        cnt--;
    }

    return ans;

}
};