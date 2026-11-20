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
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return ;
        deque<int> q;

        ListNode* tmp = head;
        while(tmp!=nullptr){
            q.push_back(tmp->val);
            tmp = tmp->next;
        }

        tmp = head;
        bool turn = true;
        while(!q.empty() && tmp!=nullptr){
           if(turn){
            // front
            tmp->val = q.front();
            q.pop_front();
           }else{
            tmp->val = q.back();
            q.pop_back();
           }
           turn = !turn;
           tmp = tmp->next;
        }
        
    }
};