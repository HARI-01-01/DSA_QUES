class Solution {
public:
    bool canAliceWin(int n) {
        int cnt = 10;

        bool turn = true;

        while(n-cnt>=0){
            n-=cnt;

            cnt--;
            turn =!turn;
        }

        return !turn;        
    }
};