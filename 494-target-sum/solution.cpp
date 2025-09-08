class Solution {
public:
    int solve(int index, int target, vector<int>& arr,
              vector<vector<int>>& dp) {
        if (index == 0) {
            if (target == 0 && arr[0] == 0)
                return 2;
            if (target == 0)
                return 1;
            if (arr[0] == target)
                return 1;
            return 0;
        }
        if (dp[index][target] != -1) {
            return dp[index][target];
        }

        int notTake = solve(index - 1, target, arr, dp);
        int take = 0;
        if (arr[index] <= target) {
            take = solve(index - 1, target - arr[index], arr, dp);
        }

        dp[index][target] = take + notTake;
        return dp[index][target];
    }

    int countPartitions(vector<int>& arr, int d) {
        int n = arr.size();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        int target = (totalSum - d) / 2;
        if (totalSum - d < 0 || (totalSum - d) % 2)
            return 0;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return solve(n - 1, target, arr, dp);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums, target);
    }
};