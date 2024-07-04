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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* prev=head;
        ListNode* curr=head->next;
        int sum=0;

        while(curr->next){
            sum+=curr->val;
            if(curr->next->val!=0){
                prev->next=curr->next;
                curr=curr->next;
            }
            else{
                curr->val=sum;
                sum=0;
                prev=curr;
                curr=curr->next;
            }
        }
        prev->next=NULL;
        return head->next;
    }
};