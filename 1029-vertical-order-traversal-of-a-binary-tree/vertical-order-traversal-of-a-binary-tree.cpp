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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>>mp;
        queue<pair<TreeNode*, pair<int,int>>>q;
        q.push({root, {0,0}});

        while(!q.empty()){
            int vert=q.front().second.first;
            int lev=q.front().second.second;
            TreeNode* node=q.front().first;
            q.pop();

            mp[vert][lev].insert(node->val);

            if(node->left){
                q.push({node->left, {vert-1, lev+1}});
            }
            if(node->right){
                q.push({node->right, {vert+1, lev+1}});
            }
        }

        vector<vector<int>>ans;
        for(auto it: mp){
            vector<int>output;
            for(auto iter: it.second){
                output.insert(output.end(), iter.second.begin(), iter.second.end());
            }
            ans.push_back(output);
        }

        return ans;
    }
};