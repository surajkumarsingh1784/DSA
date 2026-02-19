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
    ListNode* swapPairs(ListNode* head) {
        // Dummy node to handle edge cases
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prev = dummy;

        while (prev->next != NULL && prev->next->next != NULL) {
            ListNode* first = prev->next;
            ListNode* second = first->next;

            // Swapping
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move prev forward
            prev = first;
        }

        return dummy->next;
    }
};
