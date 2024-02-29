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
    bool solve(vector<int>& v, int lev){
        if(lev&1){
            for(auto it: v){
                if(it&1)
                return false;
            }

            for(int i=0;i<v.size()-1;i++){
                if(v[i+1]>=v[i])
                return false;
            }
            return true;
        }
        else{
            for(auto it: v){
                if(it%2==0)
                return false;
            }

            for(int i=0;i<v.size()-1;i++){
                if(v[i+1]<=v[i])
                return false;
            }
            return true;
        }
    }

    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        if(root==NULL){
            return false;
        }

        int level=0;
        while(!q.empty()){
            int s=q.size();
            vector<int>v;

            for(int i=0;i<s;i++){
                TreeNode* node=q.front();
                q.pop();

                v.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            if(!solve(v,level)){
                return false;
            }
            level++;
        }

        return true;
    }
};