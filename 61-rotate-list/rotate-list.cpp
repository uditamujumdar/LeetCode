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
    int total(ListNode* head){
        int cnt=0;
        while(head){
            cnt++;
            head=head->next;
        }

        return cnt;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        int tot=total(head);
        if(k==tot||k==0||head==NULL || head->next==NULL){
            return head;
        }
        k=k%tot;

        ListNode* temp=head;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=head;
        
        int kk=tot-k-1;
        temp=head;
        while(kk--){
            temp=temp->next;
        }
        ListNode* nhead=temp->next;

        temp->next=NULL;

        return nhead;
    }
};