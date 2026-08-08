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
    bool ans = true;
private:
    int rec(TreeNode* root){
        if(root == NULL) return 0;
        int l = rec(root -> left);
        int r = rec(root -> right);
        if(abs(l-r) > 1) ans = false; 
        return max(r,l) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        rec(root);
        return ans;
    }
};