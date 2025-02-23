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
    int preind=0, postind=0;
    TreeNode* f(vector<int>&pre, vector<int>&post){
        TreeNode* root=new TreeNode(pre[preind++]);

        if(root->val!=post[postind]){
            root->left=f(pre, post);
        }

        if(root->val!=post[postind]){
            root->right=f(pre, post);
        }

        postind++;

        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return f(pre, post);
    }
};