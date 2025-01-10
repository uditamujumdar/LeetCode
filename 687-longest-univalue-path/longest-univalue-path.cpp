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
    int dfs(TreeNode* root, int& maxi){
        if(!root){
            return 0;
        }
        int left=dfs(root->left, maxi);
        int right=dfs(root->right, maxi);

        if(!root->left || root->left->val!=root->val){
            left=0;
        }
        if(!root->right || root->right->val!=root->val){
            right=0;
        }
        maxi=max(maxi, left+right);
        return max(left,right)+1;
    }
    
    int longestUnivaluePath(TreeNode* root) {
        int maxi=0;
        dfs(root, maxi);
        return maxi;
    }
};