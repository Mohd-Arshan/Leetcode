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
    string serialize(TreeNode* root){
        stack<TreeNode*> stk;
        stk.push(root);

        string str = "";
        while(!stk.empty()){
            TreeNode *a = stk.top();
            stk.pop();
            if(!a){
                str += 'N';
                continue;
            }

            str += '_'+to_string(a->val);
            stk.push(a->left);
            stk.push(a->right);
        }

        return str;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string str1 = serialize(root);
        string str2 = serialize(subRoot);
        cout<<str1<<endl;
        cout<<str2;
        return str1.find(str2) != string::npos;
    }
};