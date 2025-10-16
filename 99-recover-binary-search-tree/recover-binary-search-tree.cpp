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
    void inorder(TreeNode* root, vector<TreeNode*>&temp){
        if(!root)return;
        inorder(root->left, temp);
        temp.push_back(root);
        inorder(root->right, temp);
    }

    void recoverTree(TreeNode* root) {
        vector<TreeNode*> arr;
        inorder(root, arr);
        int i = 1;
        TreeNode* first = 0;
        TreeNode* second = 0;

        while(i<arr.size()){
            if(arr[i-1]->val <= arr[i]->val){
                i++;
                continue;
            }
            else{
                if(!first)first = arr[i-1];
                second = arr[i];
                i++;
            }
        }
        swap(first->val, second->val);
    }
};