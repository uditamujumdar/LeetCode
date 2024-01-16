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
    void solve(vector<vector<int>>&ans,vector<int>& output,TreeNode* root,int target,int curr){
        if(root==NULL){
            return;
        }

        output.push_back(root->val);
        if(root->right==NULL && root->left==NULL){
            if(root->val+curr==target){
                ans.push_back(output);
            }
        }

        solve(ans,output,root->left,target, curr+root->val);
        solve(ans,output,root->right,target, curr+root->val);
        output.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int>output;

        solve(ans, output, root, targetSum, 0);

        return ans;
    }
};