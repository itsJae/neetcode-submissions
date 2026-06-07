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
        // [0, n - 1, 1, n - 2, 2, n - 3, 3, n - 4, 4];
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *right = reverse_list(slow->next);
        slow->next = nullptr;
        ListNode *left = head;       

        while (right != nullptr) {
            ListNode *next_left = left->next;
            ListNode *next_right = right->next;

            left->next = right;
            right->next = next_left;

            left = next_left;
            right = next_right;
        }
    }

    ListNode *reverse_list(ListNode *head) {
        ListNode *curr = head;
        ListNode *prev = nullptr;

        while (curr != NULL) {
            ListNode *next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }
};
