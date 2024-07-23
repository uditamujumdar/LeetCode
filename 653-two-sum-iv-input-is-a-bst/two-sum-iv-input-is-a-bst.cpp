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
    bool f(TreeNode* root, set<int>&st, int k){
        if(root==NULL){
            return false;
        }
        if(st.count(k-root->val)){
            return true;
        }
        st.insert(root->val);

        return f(root->left,st,k) || f(root->right, st, k);
    }

    bool findTarget(TreeNode* root, int k) {
        set<int>st;
        return f(root,st,k);
    }
};