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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>ans(m, vector<int>(n, -1));
        int toprow=0, bottomrow=m-1, left=0, right=n-1;

        while(head){
            for(int i=left;i<=right && head;i++){
                ans[toprow][i]=head->val;
                head=head->next;
            }
            toprow++;
            
            for(int i=toprow;i<=bottomrow && head;i++){
                ans[i][right]=head->val;
                head=head->next;
            }
            right--;
            
            for(int i=right;i>=left && head;i--){
                ans[bottomrow][i]=head->val;
                head=head->next;
            }
            bottomrow--;

            for (int i=bottomrow;i>=toprow && head;i--) {
                ans[i][left]=head->val;
                head=head->next;
            }
            left++;
        }

        return ans;
    }
};