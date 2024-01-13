/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* cl;
    TreeNode* solve(TreeNode* clone, TreeNode* target){
        if(clone==NULL){
            return NULL;
        }
        if(clone->val==target->val){
            cl=clone;
        } 

        solve(clone->left, target);
        solve(clone->right, target);

        return cl;
    }

    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return solve(cloned, target);
    }
};