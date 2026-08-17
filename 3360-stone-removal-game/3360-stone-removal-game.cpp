class Solution {
public:
    bool func(int n,int val,bool turn){
        if(n==0)  return !turn;
        if(n<val) return !turn;
        return func(n-val,val-1,!turn);
    }
    bool canAliceWin(int n) {
        return func(n,10,true);
    }
};