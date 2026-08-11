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
    int rec(TreeNode* root,int mx){
        if(root == NULL) return 0;

        int l = rec(root->left,max(mx,root->val));
        int r = rec(root->right,max(mx,root->val));

        return l + r + int(root->val >= mx);

    }
public:
    int goodNodes(TreeNode* root) {
        return rec(root,INT_MIN);
    }
};