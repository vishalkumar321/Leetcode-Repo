class Solution {
public:
    int solve(int index, int prev, vector<int>& nums, vector<vector<int>>& dp) {
        int n = nums.size();
        if (index == n)
            return 0;
        if (dp[index][prev + 1] != -1)
            return dp[index][prev + 1];

        int notTake = solve(index + 1, prev, nums, dp);
        int take = 0;
        if (prev == -1 || nums[index] % nums[prev] == 0) {
            take = 1 + solve(index + 1, index, nums, dp);
        }

        return dp[index][prev + 1] = max(take, notTake);
    }

    void build(int index, int prev, vector<int>& nums, vector<vector<int>>& dp,
               vector<int>& subset) {
        int n = nums.size();
        if (index == n)
            return;

        int notTake = solve(index + 1, prev, nums, dp);
        int take = 0;
        if (prev == -1 || nums[index] % nums[prev] == 0) {
            take = 1 + solve(index + 1, index, nums, dp);
        }

        if (take >= notTake && (prev == -1 || nums[index] % nums[prev] == 0)) {
            subset.push_back(nums[index]);
            build(index + 1, index, nums, dp, subset);
        } else {
            build(index + 1, prev, nums, dp, subset);
        }
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        vector<int> subset;
        solve(0, -1, nums, dp);
        build(0, -1, nums, dp, subset);
        return subset;
    }
};
