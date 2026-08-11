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
    bool bst(TreeNode* root,long long upper,long long lower){
        if(!root) return true;

        if(upper > root->val && root->val > lower)
        return bst(root->left,root->val,lower) && bst(root->right,upper,root->val);

        return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        return bst(root,LLONG_MAX,LLONG_MIN);
    }
};