class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
       if(!head or !head->next) return NULL;
       ListNode* fast=head;
       ListNode* slow=head;
       while(fast and fast->next){
        slow=slow->next;
        fast=fast->next->next;
       }
       ListNode* prev=NULL;
       ListNode* curr=head;
       while(curr!=slow){
        prev=curr;
        curr=curr->next;
       }
       prev->next=curr->next;
       return head;
    }
};