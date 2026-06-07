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
        ListNode *dummy = new ListNode(0);
        int carry = 0;

        ListNode *curr = dummy;
        ListNode *l1_curr = l1;
        ListNode *l2_curr = l2;
        
        while (l1_curr != nullptr || l2_curr != nullptr || carry != 0) {
            int sum = carry;
            
            if (l1_curr != nullptr) {
                sum += l1_curr->val;
                l1_curr = l1_curr->next;
            }

            if (l2_curr != nullptr) {
                sum += l2_curr->val;
                l2_curr = l2_curr->next;
            }

            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            carry = sum / 10;
        }

        return dummy->next;
    }
};
