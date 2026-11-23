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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;

        ListNode* dummayNode = new ListNode(-1);
        ListNode* curr = dummayNode;

        int carry = 0;

        while(t1!=nullptr && t2!=nullptr){
            int val = t1->val + t2->val + carry;
            ListNode* tmp = new ListNode(val%10);
            val/=10;
            carry = val;
            curr->next = tmp;
            curr = tmp;
            t1 = t1->next;
            t2 = t2->next;
        }
        while(t1!=nullptr){
            int val = t1->val + carry;
            ListNode* tmp = new ListNode(val%10);
            val/=10;
            carry = val;
            curr->next = tmp;
            curr = tmp;
            t1 = t1->next;
        }
         while(t2!=nullptr){
            int val = t2->val + carry;
            ListNode* tmp = new ListNode(val%10);
            val/=10;
            carry = val;
            curr->next = tmp;
            curr = tmp;
            t2 = t2->next;
        }
        if(carry!=0){
            ListNode* tmp = new ListNode(carry);
            curr->next = tmp;
        }
        dummayNode = dummayNode->next;

        return dummayNode;
        
    }
};