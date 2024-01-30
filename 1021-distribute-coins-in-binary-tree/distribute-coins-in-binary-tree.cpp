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
    int solve(TreeNode* root, int& cnt){
        if(!root){
            return 0;
        }

        int l=solve(root->left, cnt);
        int r=solve(root->right, cnt);

        cnt+=(abs(l)+abs(r));

        return root->val+l+r-1;
    }

    int distributeCoins(TreeNode* root) {
        int cnt=0;
        solve(root, cnt);
        return cnt;
    }
};