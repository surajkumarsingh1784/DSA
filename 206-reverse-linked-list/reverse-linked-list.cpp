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
        // Base case: agar list empty hai ya sirf 1 element hai
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // recursion se baaki list reverse kar do
        ListNode* newHead = reverseList(head->next);

        // ab current node ka link reverse karo
        head->next->next = head;
        head->next = NULL;

        return newHead;
    }
};
