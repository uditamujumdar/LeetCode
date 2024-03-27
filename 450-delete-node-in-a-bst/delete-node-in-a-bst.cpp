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
    TreeNode* findmin(TreeNode* root) {
        if(root==NULL)return root;

        while(root->left!=NULL){
            root=root->left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        if(root->val==key){
            if(!root->left && !root->right){
                delete root;
                return NULL;
            }
            if(root->left && !root->right){
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }
            if(root->right && !root->left){
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }
            if(root->left && root->right){
                int mini=findmin(root->right)->val;
                root->val=mini;
                root->right=deleteNode(root->right, mini);
                return root;
            }
        }
        else if(root->val>key){
            root->left=deleteNode(root->left, key);
            return root;
        }
        else{
            root->right=deleteNode(root->right, key);
            return root;
        }
        return root;
    }
};