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
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        map<int,TreeNode*>mp;
        set<int>st;

        for(auto it: des){
            int par=it[0], ch=it[1], left=it[2];

            if(mp.find(par)==mp.end()){
                mp[par]=new TreeNode(par);
            }
            if(mp.find(ch)==mp.end()){
                mp[ch]=new TreeNode(ch);
            }
            if(left==1){
                mp[par]->left=mp[ch];
            }
            else{
                mp[par]->right=mp[ch];
            }

            st.insert(ch);
        }

        for(auto it: des){
            if(st.find(it[0])==st.end()){
                return mp[it[0]];
            }
        }
        return NULL;
    }
};