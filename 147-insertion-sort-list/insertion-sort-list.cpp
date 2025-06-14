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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;
        ListNode* curr=head, *nex=NULL;
        while(curr){
            nex=curr->next;
            temp=dummy;
            while(temp->next and temp->next->val < curr->val){
                temp=temp->next;
            }
                curr->next=temp->next;
                temp->next=curr;
                curr=nex;
            }
           
       
         return dummy->next;
    }
};