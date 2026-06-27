class Solution {
public:
    void permutation(int index, int n, vector<int>& nums,
                     vector<vector<int>>& ans) {

        if (index == n) {
            ans.push_back(nums);
            return;
        }

        for (int i = index; i < n; i++) {
            swap(nums[index], nums[i]);
            permutation(index + 1, n, nums, ans);
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        permutation(0, n, nums, ans);
        return ans;
    }
};