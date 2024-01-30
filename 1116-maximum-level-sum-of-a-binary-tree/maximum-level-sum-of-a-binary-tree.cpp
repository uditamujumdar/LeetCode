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
    int maxLevelSum(TreeNode* root) {
        int maxi=INT_MIN;
        int level=1;
        int ans=-1;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int s=q.size();
            int sum=0;
            for(int i=0;i<s;i++){
                TreeNode* temp=q.front();
                q.pop();
                sum+=temp->val;
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right); 
            }
            if(sum>maxi){
                maxi=sum;
                ans=level;
            }
            level++;
        }

        return ans;
    }
};