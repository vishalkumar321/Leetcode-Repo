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
    void dfs(TreeNode* root, int targetSum, vector<vector<int>>& ans,
             vector<int>& current) {
        if (!root)
            return;

        current.push_back(root->val);
        if (!root->left && !root->right && targetSum == root->val) {
            ans.push_back(current);
        }

        dfs(root->left, targetSum - root->val, ans, current);
        dfs(root->right, targetSum - root->val, ans, current);
        current.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> current;

        dfs(root, targetSum, ans, current);
        return ans;
    }
};