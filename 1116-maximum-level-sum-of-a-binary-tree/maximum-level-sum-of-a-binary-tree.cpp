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
    int maxLevelSum(TreeNode* root) {
        if (!root)
            return 0;

        queue<TreeNode*> q;
        q.push(root);

        int maxSum = INT_MIN;
        int level = 0;
        int anslvl = 0;

        while (!q.empty()) {
            int lvlSum = 0;
            int size = q.size();
            level++;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                lvlSum += node->val;

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            if (lvlSum > maxSum) {
                maxSum = lvlSum;
                anslvl = level;
            }
        }
        return anslvl;
    }
};