class Solution {
public:
vector<int> mon = {0,31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
    int countDaysTogether(string AL, string LA, string AB, string LB) {
        int aaM = (AL[0]-'0')*10 + AL[1]-'0';
        int aaD = (AL[3]-'0')*10 + AL[4]-'0';

        int alM = (LA[0]-'0')*10 + LA[1]-'0';
        int alD = (LA[3]-'0')*10 + LA[4]-'0';

        int baM = (AB[0]-'0')*10 + AB[1]-'0';
        int baD = (AB[3]-'0')*10 + AB[4]-'0';

        int blM = (LB[0]-'0')*10 + LB[1]-'0';
        int blD = (LB[3]-'0')*10 + LB[4]-'0';

        int leftM,leftD;
        int rigM,rigD;

        // cout<<aaD<<":"<<aaM<<endl;
        // cout<<baD<<":"<<baM<<endl;

        if (aaM > baM) {
            leftM = aaM;
            leftD = aaD;
        }else if (aaM<baM) {
            leftM = baM;
            leftD = baD;
        }else {
            leftM = aaM;
            if (aaD>=baD) {
                leftD = aaD;
            }else if (aaD<baD) {
                leftD = baD;
            }
        }

        if (alM<blM) {
            rigM = alM;
            rigD = alD;
        }else if (alM>blM) {
            rigM = blM;
            rigD = blD;
        }else {
            rigM = blM;
            if (alD<=blD) {
                rigD = alD;
            }else {
                rigD = blD;
            }
        }
        // cout<<leftD<<":"<<leftM<<endl;
        // cout<<rigD<<":"<<rigM<<endl;
        if (leftM>rigM) return 0;
        else if (leftM == rigM) {
            if (leftD>rigD) return 0;
        }
        int val = (mon[rigM-1] + rigD) - (mon[leftM-1]+leftD);
        if (val<0) return 0;

        return val+1;



    }
};