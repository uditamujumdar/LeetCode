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
class FindElements {
public:
    TreeNode* root;
    void f(TreeNode* node, int value){
        if(!node){
            return;
        }
        node->val=value;

        if(node->left){
            f(node->left, 2*value+1);
        }

        if(node->right){
            f(node->right, 2*value+2);
        }
    }

    FindElements(TreeNode* root) {
        this->root=root;
        if(root){
            f(root, 0);
        }
    }
    
    bool search(TreeNode* node, int target){
        if(!node){
            return false;
        }
        if(node->val==target){
            return true;
        }
        return search(node->right, target)||search(node->left, target);
    }

    bool find(int target) {
        return search(root, target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */