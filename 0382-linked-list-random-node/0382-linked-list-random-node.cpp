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
    int cnt;
    ListNode* test;
    Solution(ListNode* head) {
        ListNode* tmp = head;
        test = head;
        int ct = 0;
        while(tmp!=nullptr){
            ct++;
            tmp = tmp->next;
        }
        cnt = ct;
    }
    
    int getRandom() {
        int num = 0 + rand() % (cnt);
        ListNode* tmp = test;
        int cnt = 0;
        int ans = -1;
        while(tmp!=nullptr){
            if(cnt == num){
                ans =  tmp->val;
                break;
            }
            cnt++;
            tmp = tmp->next;

        }
        return ans;
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */