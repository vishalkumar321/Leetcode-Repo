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
    int maxi(vector<int>& nums, int left, int right) {

        int maxIdx = left;
        for (int i = left; i <= right; i++) {
            if (nums[maxIdx] < nums[i]) {
                maxIdx = i;
            }
        }
        return maxIdx;
    }

    TreeNode* tree(vector<int>& nums, int left, int right) {
        if (left > right)
            return NULL;

        int maxIdx = maxi(nums, left, right);
        TreeNode* root = new TreeNode(nums[maxIdx]);
        root->left = tree(nums, left, maxIdx - 1);
        root->right = tree(nums, maxIdx + 1, right);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return tree(nums, 0, nums.size() - 1);
    }
};