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

    int getDepth(TreeNode* node, bool traverse){
        int depth =0;

        while(node){
            node = traverse ? node->left : node->right;
            depth++;
        }
        return depth;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;

        int leftDepth = getDepth(root , true);
        int rightDepth = getDepth(root , false);

        if(leftDepth == rightDepth){
            return (1 << leftDepth) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};