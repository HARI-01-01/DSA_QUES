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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* tmp = head->next;
        ListNode* curr = head;
        ListNode* next = tmp;

        while(next!=nullptr&&next->next!=nullptr){
            curr->next = next->next;
            curr = curr->next;
            next->next = curr->next;
            next = next->next;
        }
        curr->next = tmp;

        return head;
        
    }
};