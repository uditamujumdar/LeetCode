/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int ans,sum;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        sum=0;
        ans=root->val;

        while(!q.empty()){
            TreeNode* node=q.front();
            if(node==NULL && q.size()==1){
                break;
            }

            if(node==NULL){
                ans=sum;
                sum=0;
                q.push(NULL);
            }

            else{
                if(node->left){
                    q.push(node->left);
                    sum+=node->left->val;
                }
                if(node->right){
                    q.push(node->right);
                    sum+=node->right->val;
                }
            }
            q.pop();
        }

        return ans;

    }
};