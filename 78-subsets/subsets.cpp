class Solution {
public:
    void solve(int idx, vector<int>& nums, vector<int>& curr,
               vector<vector<int>>& ans) {

        if (idx < 0) {
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[idx]);
        solve(idx - 1, nums, curr, ans);
        curr.pop_back();
        solve(idx - 1, nums, curr, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> curr;
        vector<vector<int>> ans;

        solve(n - 1, nums, curr, ans);
        return ans;
    }
};