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
    void rec(TreeNode* root,int mx,int& gn){
        if(root == NULL) return;

        if(root->val >= mx){
            gn++;
        }

        rec(root->left,max(mx,root->val),gn);
        rec(root->right,max(mx,root->val),gn);
        
        return;

    }
public:
    int goodNodes(TreeNode* root) {
        int ans = 0;
        rec(root,INT_MIN,ans);
        return ans;
    }
};