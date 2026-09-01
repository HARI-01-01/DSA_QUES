/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> arr;
        while(head!=nullptr){
            arr.push_back(head->val);
            head = head->next;
        }
       int n = arr.size();
        vector<int> idx;
        for(int i=1;i<n-1;i++){
            if(arr[i-1] > arr[i] && arr[i] < arr[i+1]){
                idx.push_back(i);
            }else if(arr[i-1] < arr[i] && arr[i] > arr[i+1]){
                idx.push_back(i);
            }
        }
    if (idx.size()<2) return {-1,-1};
    int mini = INT_MAX;
    for (int i=1;i<idx.size();i++) {
        mini = min(mini,abs(idx[i-1]-idx[i]));
    }
    return {mini,idx[idx.size()-1]-idx[0]};
          
        
    }
};