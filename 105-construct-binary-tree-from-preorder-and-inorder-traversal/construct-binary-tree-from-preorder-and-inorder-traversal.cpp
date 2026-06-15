/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int find(vector<int>& inorder, int target, int start, int end) {

        for (int i = start; i <= end; i++) {
            if (inorder[i] == target) {
                return i;
            }
        }
        return -1;
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& idx,
                     int start, int end) {
        if (start > end) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[idx]);
        idx++;
        if (start == end)
            return root;
        int pos = find(inorder, root->val, start, end);
        root->left = helper(preorder, inorder, idx, start, pos - 1);
        root->right = helper(preorder, inorder, idx, pos + 1, end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int idx = 0;
        return helper(preorder, inorder, idx, 0, n - 1);
    }
};