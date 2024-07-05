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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return {-1,-1};
        }

        ListNode* prev=head;
        ListNode* curr=head->next;
        vector<int>v;
        int x=2;

        while(curr->next){
            if(curr->val>prev->val && curr->val>curr->next->val){
                v.push_back(x);
            }
            else if(curr->val<prev->val && curr->val<curr->next->val){
                v.push_back(x);
            }
            prev=curr;
            curr=curr->next;
            x++;
        }
    
        if(v.size()<2){
            return {-1,-1};
        }

        int mini=INT_MAX;
        int maxi=v[v.size()-1]-v[0];

        for(int i=1;i<v.size();i++){
            mini=min(mini, v[i]-v[i-1]);
        }

        return {mini,maxi};
    }
};