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
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* fwd=nullptr;
        while(curr!=NULL){
            fwd=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fwd;
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        if(head->next==NULL|| head->next->next==NULL){
            return;
        }
        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast){
            slow=slow->next;
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
            }
        }

        ListNode* ptr=head;
        ListNode* ptrn=ptr->next;
        ListNode* qtr=reverseList(slow);
        ListNode* qtrn=qtr->next;

        while(qtrn && ptrn){
            ptr->next = qtr;
            qtr->next = ptrn;
            ptr = ptrn;
            ptrn = ptrn->next;
            qtr = qtrn;
            qtrn = qtrn->next;
        }
    }
};