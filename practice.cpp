#include<iostream>
#include<vector>
using namespace std;
int main(){

    vector<int> arr= {1,2,3,4,5,3,2,1};

         int n = arr.size()-1;
        int max = 0;
        int idx;
        for(int i=0;i<=n;i++){
            if(arr[i]>max){
                max = arr[i];
                idx = i;
            }
        }
        cout<<max <<" "<<idx;





    return 0;
}