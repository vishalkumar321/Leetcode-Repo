class Solution {
public:
    void subseq(vector<int>& result, vector<vector<int>>& ans,
                vector<int>& nums, int n, int index) {
        if (n == index) {
            ans.push_back(result);
            return;
        }
        
        subseq(result, ans, nums, n, index + 1);
        result.push_back(nums[index]);
        subseq(result, ans, nums, n, index + 1);
        result.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> result;
        subseq(result, ans, nums, nums.size(), 0);
        return ans;
    }
};