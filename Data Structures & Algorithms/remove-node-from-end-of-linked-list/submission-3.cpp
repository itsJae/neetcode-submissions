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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0, head);

        ListNode *slow = dummy;
        ListNode *fast = dummy;

        for (int i = 0; i <= n; ++i) 
            fast = fast->next;
        
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode *to_delete = slow->next;
        slow->next = slow->next->next;
        delete to_delete;

        head = dummy->next;
        delete dummy;

        return head;
        // int len = 0;
        // ListNode *curr = head;

        // while (curr != nullptr) {
        //     len++;            
        //     curr = curr->next;
        // }

        // int delete_pos = len - n; 
        // int curr_pos = 0;

        // curr = head;
        // ListNode *prev = nullptr;
        
        // while (curr != nullptr && curr_pos <= delete_pos) {
        //     if (curr_pos == delete_pos) {
        //         if (prev == nullptr) {
        //             return head->next;
        //         }

        //         prev->next = curr->next;
        //     }

        //     ++curr_pos;
        //     prev = curr;
        //     curr = curr->next;
        // }

        // return head;
    }
};
