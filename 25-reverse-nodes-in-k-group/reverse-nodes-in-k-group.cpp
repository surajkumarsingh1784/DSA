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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1) return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prevGroup = dummy;

        while (true) {
            // Step 1: check k nodes exist or not
            ListNode* kth = prevGroup;
            for (int i = 0; i < k; i++) {
                kth = kth->next;
                if (kth == NULL)
                    return dummy->next;
            }

            // Step 2: reverse k nodes
            ListNode* nextGroup = kth->next;
            ListNode* curr = prevGroup->next;
            ListNode* prev = nextGroup;

            while (curr != nextGroup) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // Step 3: connect previous group
            ListNode* temp = prevGroup->next;
            prevGroup->next = kth;
            prevGroup = temp;
        }
    }
};
