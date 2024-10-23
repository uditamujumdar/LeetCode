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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(!root){
            return root;
        }
        queue<TreeNode*>q;
        q.push(root);
        int prev=root->val;

        while(!q.empty()){
            int size=q.size();
            int sum=0;
           
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
                q.pop();
                int leftRight = (temp->left ? temp->left->val : 0) + (temp->right ? temp->right->val : 0);
                
                if(temp->left){
                    temp->left->val=leftRight;
                    q.push(temp->left);
                }
                if(temp->right){
                    temp->right->val=leftRight;
                    q.push(temp->right);
                }
                sum+=leftRight;
                temp->val=prev-temp->val;
            }
            prev=sum;
        }
        return root;
    }
};