class Solution {
public:
    int evalRPN(vector<string>& arr) {
    int n = arr.size();
    stack<string> st;

    int i = 0;
    while(i<n){
        string ch = arr[i];
        if(ch!="/" && ch!="*" && ch!="+" && ch!="-"){
            // cout<<"it a number."<<endl;
            st.push(arr[i]);
            // print_stack(st);
        }else{
            // cout<<"it an operator"<<endl;
            // we a operator now
            int a,b;
            if (!st.empty()) {
                b = stoi(st.top());
                st.pop();
            }
            if (!st.empty()) {
                a = stoi(st.top());
                st.pop();
            }
            // cout<<"a: "<<a<<" b: "<<b<<endl;
            // cout<<"stack: ";

            if(arr[i] == "/"){
                st.push(to_string(a/b));
            }else if(arr[i]=="*"){
                st.push(to_string(a*b));
            }else if(arr[i]=="+"){
                st.push(to_string(a+b));
            }else{
                st.push(to_string(a-b));
            }
            // print_stack(st);
        }
        i++;
        // cout<<endl;
        // cout<<endl;

    }
    return stoi(st.top());
}
};