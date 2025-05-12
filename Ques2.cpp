//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
//CODE FOR THE PAINTER PARTITION PROBLEM

class Solution {
  public:
  
  bool isPossible(vector<int> &arr,int k,int n, int mid){
      int painter = 1;
      int tim = 0;
      
      for(int i=0;i<n;i++){
          if(arr[i]+tim<=mid){
              tim = tim +arr[i];
              
          }else{
              painter++;
              tim = arr[i];
          }
      }
      
      return k>=painter ? true : false;
  }
    int minTime(vector<int>& arr, int k) {
        int n = arr.size();
        // code here
        int max = 0;
        int sum = 0;
        for(int i=0;i<n;i++){
            if(arr[i]>max){
                max = arr[i];
            }
            sum +=arr[i];
        }
        
        int str = max, end = sum;
        int ans = -1;
        
        while(str<=end){
            int mid = str + (end-str)/2;
            if(isPossible(arr,k,n,mid)){
                ans = mid;
                end = mid -1;
            }else{
                str = mid +1;
            }
        }
        return ans;
        
        
        // return minimum time
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution obj;
        cout << obj.minTime(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends