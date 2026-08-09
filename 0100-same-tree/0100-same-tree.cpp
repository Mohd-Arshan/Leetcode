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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> stk1,stk2;

        stk1.push(p);
        stk2.push(q);

        while(!stk1.empty() && !stk2.empty()){
            TreeNode* a = stk1.top(); stk1.pop();
            TreeNode* b = stk2.top(); stk2.pop();
            if(!a && !b) continue;

            if(!a || !b || (a->val != b->val)) return false;

            stk1.push(a->left);
            stk1.push(a->right);
            stk2.push(b->left);
            stk2.push(b->right);
        }

        return stk1.empty() && stk2.empty();
    }
};