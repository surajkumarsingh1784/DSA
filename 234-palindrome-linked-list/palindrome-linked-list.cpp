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
       if(head==NULL || head->next==NULL){
        return head;
       }
       ListNode* prev=NULL;
       ListNode* curr=head;
       ListNode* Next=NULL;
       while(curr!=NULL){ 
       Next=curr->next;
       curr->next=prev;
       prev=curr;
       curr=Next;
       }
       return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newhead=reverseList(slow->next);
        ListNode* a=head;
        ListNode*b=newhead;
        while(b){
            if(a->val!=b->val) return false;
            a=a->next;
            b=b->next;
        }
        return true;
    }
};