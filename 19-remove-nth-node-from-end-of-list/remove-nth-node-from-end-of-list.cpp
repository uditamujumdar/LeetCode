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
        ListNode* curr=head;
        while(curr!=NULL){
            cnt++;
            curr=curr->next;
        }
        return cnt;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL){
            return NULL;
        }
        int tot=total(head);

        if(tot==1){
            return NULL;
        }
        if(tot==n){
            return head->next;
        }
        
        ListNode* curr=head;

        int cnt=0;
        while(cnt<tot-n-1){
            curr=curr->next;
            cnt++;
        }

        curr->next=curr->next->next;

        return head;
    }
};