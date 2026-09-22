class Solution {
public:
    int evalRPN(vector<string>& arr) {
    int n = arr.size();
    stack<int> st;

    int i = 0;
    while(i<n){
        string ch = arr[i];
        if(ch!="/" && ch!="*" && ch!="+" && ch!="-"){
            // cout<<"it a number."<<endl;
            st.push(stoi(ch));
            // print_stack(st);
        }else{
            // cout<<"it an operator"<<endl;
            // we a operator now
            int a,b;
            if (!st.empty()) {
                b = (st.top());
                st.pop();
            }
            if (!st.empty()) {
                a = (st.top());
                st.pop();
            }
            // cout<<"a: "<<a<<" b: "<<b<<endl;
            // cout<<"stack: ";

            if(ch == "/"){
                st.push((a/b));
            }else if(ch=="*"){
                st.push((a*b));
            }else if(ch=="+"){
                st.push((a+b));
            }else{
                st.push((a-b));
            }
            // print_stack(st);
        }
        i++;
        // cout<<endl;
        // cout<<endl;

    }
    return (st.top());
}
};