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
    int f(TreeNode* root, int low, int high, int& sum){
        if(root==NULL){
            return 0;
        }

        f(root->left, low, high, sum);
        int x=root->val;
        if(x>=low && x<=high){
            sum+=x;
        }
        f(root->right, low, high, sum);

        return sum;

    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        return f(root, low, high, sum);
    }
};