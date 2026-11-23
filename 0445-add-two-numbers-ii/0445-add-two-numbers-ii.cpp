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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        ListNode* prev = NULL;
        ListNode* temp = head;
        while(temp != NULL){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1,s2;

        while(l1!=nullptr){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2!=nullptr){
            s2.push(l2->val);
            l2 = l2->next;
        }
        ListNode* dummayNode = new ListNode(-1);
        ListNode* curr = dummayNode;

        int carry = 0;
        while(!s1.empty() && !s2.empty()){
            int val = s1.top() + s2.top() + carry;
            s1.pop(); s2.pop();

            ListNode* tmp = new ListNode(val%10);
            val/=10;
            carry = val;

            curr->next= tmp;
            curr=tmp;
        }
        while(!s1.empty()){
            int val = s1.top() +  carry;
            s1.pop(); 

            ListNode* tmp = new ListNode(val%10);
            val/=10;
            carry = val;

            curr->next= tmp;
            curr=tmp;
        }
        while(!s2.empty()){
            int val = s2.top() +  carry;
            s2.pop(); 

            ListNode* tmp = new ListNode(val%10);
            val/=10;
            carry = val;

            curr->next= tmp;
            curr=tmp;
        }

        if(carry!=0){
            ListNode* tmp = new ListNode(carry%10);
            curr->next= tmp;
        }

        dummayNode = dummayNode->next;

        return reverseList(dummayNode);
    }
};