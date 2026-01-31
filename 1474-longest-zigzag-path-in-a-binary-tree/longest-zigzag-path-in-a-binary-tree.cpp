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
    int maxPath = 0;
    void countZigZag(TreeNode* root, bool zigzag, int count) {

        if(!root)return ;
        maxPath = max(maxPath, count);
        if (zigzag) {
            countZigZag(root->left, false, count + 1);
            countZigZag(root->right, true, 1);
        } else {
            countZigZag(root->right, true, count + 1);
            countZigZag(root->left, false, 1);
        }
    }

    int longestZigZag(TreeNode* root) {

        countZigZag(root, true, 0);
        return maxPath;
    }
};