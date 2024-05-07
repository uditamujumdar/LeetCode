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
    ListNode* reverse(ListNode* head) {
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

    ListNode* doubleIt(ListNode* head) {
        ListNode* nhead=reverse(head);
        ListNode* curr=nhead;
        ListNode* prev=NULL;
        int carry=0;

        while(curr){
            int doub=curr->val*2+carry;
            curr->val=doub%10;

            if(doub>9){
                carry=1;
            }
            else{
                carry=0;
            }
            prev=curr;
            curr=curr->next;
        }
        if(carry!=0){
            ListNode* newnode=new ListNode(carry);
            prev->next=newnode;
        }

        return reverse(nhead);
    }
};