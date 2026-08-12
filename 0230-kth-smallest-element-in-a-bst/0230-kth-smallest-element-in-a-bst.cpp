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
    bool flag = true;
    void rec(TreeNode* root,int k){
        if(!root) return;

        if(flag) rec(root->left,k);
        count++;
        if(count == k){
            ans = root->val;
            flag = false;
            return;
        }
        if(flag) rec(root->right,k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        rec(root,k);
        return ans;
    }
};