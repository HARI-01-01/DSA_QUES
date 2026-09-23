class Solution {
public:
    int calculate(string s) {
    long long  num = 0;
    long long sign = 1; // 1 - pos, 0 - neg
    long long result = 0;
    stack<int> st;

    for (char ch:s) {
        if (ch!='+' && ch!='-' && ch!='(' && ch!=')'&&ch!=' ') {
            num = num*10+(ch-'0');
        }else if (ch=='+') {
            result+= sign*num;
            sign = 1;
            num = 0;
        }else if (ch == '-') {
            result+=sign*num;
            sign=-1;
            num = 0;
        }else if (ch=='(') {
            st.push(result);
            st.push(sign);
            sign = 1;
            result = 0;
        }else if (ch ==')') {
            result+=sign*num;
            result*=st.top(); st.pop();
            result+=st.top(); st.pop();
            num = 0;
        }
    }
    result+= sign*num;
    return result;
}
};