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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        vector<int>output;
        queue<TreeNode*>q;
        if(root==NULL){
            return {};
        }
        q.push(root);

        bool flag=false;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
                output.push_back(temp->val);
                q.pop();
                if(temp->left)q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(flag){
                reverse(output.begin(), output.end());
            }
            ans.push_back(output);
            output.clear();
            flag=!flag;
        }

        return ans;
    }
};