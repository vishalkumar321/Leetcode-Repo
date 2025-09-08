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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>> ans;
        TreeNode* temp;

        if(root == nullptr)return ans;

        while(!q.empty()){
            int levelSize = q.size();
            vector<int>level;

            for(int i=0; i<levelSize; i++){
                temp = q.front();
                q.pop();

                level.push_back(temp->val);

                if(temp->left){
                    q.push(temp->left);
                }

                if(temp->right){
                    q.push(temp->right);
                }
            } 
            ans.push_back(level); 
        }
        return ans;
    }
};