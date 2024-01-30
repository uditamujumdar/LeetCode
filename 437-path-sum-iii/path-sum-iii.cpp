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
    long long pathcount;
    void getsum(TreeNode* root, long long sum){
        if(!root)return;
        if(root->val==sum){
            pathcount++;
        }
        getsum(root->left,sum-root->val);
        getsum(root->right,sum-root->val);
    }

    int pathSum(TreeNode* root, int sum) {
        if(root){
            getsum(root,sum);
            pathSum(root->left,sum);
            pathSum(root->right,sum);
        }
        return pathcount;
    }
};