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
    TreeNode* f(TreeNode* root, int tar){
        if(root==NULL){
            return root;
        }
        if(root->left)
        root->left=f(root->left, tar);

        if(root->right)
        root->right=f(root->right, tar);

        if(root->left==NULL && root->right==NULL && root->val==tar){
            return NULL;
        }

        return root;
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return f(root, target);
    }
};