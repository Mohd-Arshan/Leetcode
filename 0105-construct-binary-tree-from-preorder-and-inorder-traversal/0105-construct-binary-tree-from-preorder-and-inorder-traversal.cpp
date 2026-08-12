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
    TreeNode* build(vector<int>& preorder,int& preOrderIdx, int low, int high,unordered_map<int,int>& index){

        if(low>high) return NULL;
        int val = preorder[preOrderIdx++];
        TreeNode* root = new TreeNode(val);
        int mid = index[val];

        root->left = build(preorder,preOrderIdx,low,mid-1,index);
        root->right = build(preorder,preOrderIdx,mid+1,high,index);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int,int> index;
        for(int i=0; i<n; i++) index[inorder[i]] = i;
        int i = 0;

        return build(preorder,i,0,n-1,index);
    }
};