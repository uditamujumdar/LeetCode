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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* temp=new ListNode(0, head);

        int presum=0;
        unordered_map<int, ListNode*>mp;
        mp[0]=temp;

        while(head!=NULL){
            presum+=head->val;
            mp[presum]=head;
            head=head->next;
        }

        head=temp;
        presum=0;

        while(head!=NULL){
            presum+=head->val;
            head->next=mp[presum]->next;
            head=head->next;
        }

        return temp->next;
    }
};