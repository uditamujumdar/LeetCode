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
    int solve(TreeNode* root, int maxi, int mini){
        if(root == NULL) 
        {
            return maxi - mini;
        }
        maxi = max(maxi, root->val);
        mini = min(mini, root->val);
        int lap1= solve(root->left, maxi, mini);
        int rep1= solve(root->right, maxi, mini);
        return max(lap1, rep1);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        return solve(root, maxi, mini);
    }
};