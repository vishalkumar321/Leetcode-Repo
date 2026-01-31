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
    int countFromNode(TreeNode* root, long long targetSum) {
        int count = 0;

        if (!root)
            return 0;

        if (targetSum == root->val) {
            count++;
        }

        count += countFromNode(root->left, targetSum - root->val);
        count += countFromNode(root->right, targetSum - root->val);
        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root)
            return 0;

        return countFromNode(root, (long long)targetSum) + 
                    pathSum(root->left, targetSum) +
                    pathSum(root->right, targetSum);
    }
};