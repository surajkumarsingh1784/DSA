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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode*curr=list1;
        a--;
        while(a--){
            curr=curr->next;
        }
        b++;
        ListNode*curr2=list1;
        while(b--){
            curr2=curr2->next;
        }
        ListNode*temp=list2;
        while(temp->next) temp=temp->next;
        temp->next=curr2;
        curr->next=list2;
        return list1;
    }
};