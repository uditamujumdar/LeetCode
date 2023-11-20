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
    int f(TreeNode* root, int& maxi){
        if(root==NULL){
            return 0;
        }

        //max(0, f) because we do not consider a negative sum and instead return
        // zero in that case...
        int l=max(0, f(root->left, maxi));
        int r=max(0, f(root->right, maxi));

        maxi=max(maxi, l+r+root->val);

        return root->val+max(l,r);
        
    }
    
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        f(root, maxi);
        return maxi;
    }
};