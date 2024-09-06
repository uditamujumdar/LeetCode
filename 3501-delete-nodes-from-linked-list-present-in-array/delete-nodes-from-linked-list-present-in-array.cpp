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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if(head==NULL){
            return head;
        }
        
        map<int,int>mp;
        for(auto it: nums){
            mp[it]++;
        }
        while(head){
            if(mp.find(head->val)!=mp.end()){
                head=head->next;
            }
            else{
                break;
            }
        }
        
        ListNode* temp=head;
        while(temp->next){
            if(mp.find(temp->next->val)!=mp.end()){
                temp->next=temp->next->next;
            }
            else{
                temp=temp->next;
            }
        }
        
        return head;
    }
};