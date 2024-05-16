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
    bool f(TreeNode* root){
        if(root->left==NULL && root->right==NULL){
            return root->val;
        }
        if(root->left!=NULL && root->right!=NULL){
            if(root->val==2){
                return f(root->left)||f(root->right);
            }
            if(root->val==3){
                return f(root->left)&&f(root->right);
            }
        }
        return true;
    }

    bool evaluateTree(TreeNode* root) {
        if(root==NULL){
            return false;
        }
        return f(root);
    }
};