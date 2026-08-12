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
    int count = 0, ans = 0;
    void rec(TreeNode* root,int k){
        if(!root) return;

        rec(root->left,k);
        count++;
        if(count > k) return;
        if(count == k){
            ans = root->val;
            return;
        }
        rec(root->right,k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        rec(root,k);
        return ans;
    }
};