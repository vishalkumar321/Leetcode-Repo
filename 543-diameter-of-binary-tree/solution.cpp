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
    int ans =0;
    int maxDepth(TreeNode* root) {
        
        if(root==NULL)return 0;

        int leftSTH = maxDepth(root->left);
        int rightSTH = maxDepth(root->right);

        ans = max(ans , leftSTH + rightSTH);
        return max(leftSTH,rightSTH) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return ans;
    }
};