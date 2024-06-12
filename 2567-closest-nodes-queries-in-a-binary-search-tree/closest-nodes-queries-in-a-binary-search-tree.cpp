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
private:
int closest(vector<int>&bs,int x)
{
    int low=0;
    int high=bs.size()-1;

    while(low<=high)
    {
        int mid=low+(high-low)/2;

        if(bs[mid]<=x)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return high;
}
void inorder(TreeNode*root,vector<int>&bs)
{
    if(!root)
    {
        return;
    }

    inorder(root->left,bs);

    bs.push_back(root->val);

    inorder(root->right,bs);
}
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int>bs;
        //cout<<"Helk"<<endl;
        inorder(root,bs);
        vector<vector<int>>ans;
        //for(auto it:bs)cout<<it<<" ";
        for(auto it:queries)
        {
            vector<int>temp;
            int lower=lower_bound(bs.begin(),bs.end(),it)-bs.begin();//MAXi
            int upper=closest(bs,it);

            if(upper<bs.size())
            {
                temp.push_back(bs[upper]);
            }
            else
            {
                temp.push_back(-1);
            }
            if(lower<bs.size())
            {
                temp.push_back(bs[lower]);
            }
            else
            {
                temp.push_back(-1);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};