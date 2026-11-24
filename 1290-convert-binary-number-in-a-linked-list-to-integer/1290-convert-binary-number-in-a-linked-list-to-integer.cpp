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
    int getDecimalValue(ListNode* head) {
        if(head==nullptr) return 0;
        string s;

        while(head!=nullptr){
            if(head->val==1) s+='1';
            else s+='0';
            head = head->next;
        }

        reverse(s.begin(),s.end());

        int ans = 0;
        int pro = 1;

        for(char c:s){
            ans += pro*(c-'0');
            pro*=2;
        }
        return ans;
    }
};