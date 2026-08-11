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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        vector<int>ans;

        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* temp = q.front();
                q.pop();
                if(!temp) continue;
                if(ans.size() == level) ans.push_back(-1);
                ans[level] = temp->val;
                q.push(temp->left);
                q.push(temp->right);
            }
            level++;
        }

        return ans;
    }
};