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
        int cnt=1;
        while(head){
            cnt++;
            head=head->next;
        }
        return cnt;
    }

    ListNode* swapNodes(ListNode* head, int k) {
        int n=total(head);
        int i=1;
        int beg,end;

        ListNode* temp=head;
        while(temp){
            if(i==k){
                beg=temp->val;
            }
            if(i==n-k){
                end=temp->val;
            }
            i++;
            temp=temp->next;
        }

        i=1;
        temp=head;

        while(temp){
            if(i==k){
                temp->val=end;
            }
            if(i==n-k){
                temp->val=beg;
            }
            i++;
            temp=temp->next;
        }

        return head;
    }
};