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
int val=0;

    TreeNode* f(TreeNode* root){
        if(!root){
            return root;
        }
        if(root->right){
            f(root->right);
        }
        val=root->val=val+root->val;
        if(root->left){
            f(root->left);
        }

        return root;
    }

    TreeNode* bstToGst(TreeNode* root) {
        return f(root);
    }
};