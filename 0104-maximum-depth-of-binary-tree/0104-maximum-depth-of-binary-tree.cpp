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
    int len(TreeNode* root){
        if(root == NULL) return 0;
        return max(len(root->left)+1,len(root->right)+1);
    }
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return len(root);
    }
};