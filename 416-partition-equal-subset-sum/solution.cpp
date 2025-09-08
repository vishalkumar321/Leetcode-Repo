// BOTTOM UP APPROACH
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 != 0)
            return false;

        int target = sum / 2;

        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;

        for (int index = 1; index < n; index++) {
            for (int t = 1; t <= target; t++) {
                bool notTake = dp[index - 1][t];
                bool take = false;
                if (nums[index] <= t) {
                    take = dp[index - 1][t - nums[index]];
                }
                dp[index][t] = take || notTake;
            }
        }
        return dp[n - 1][target];
    }
};

// TOP-DOWN APPROACH
// class Solution {
// public:
//     bool solve(int index, int target, vector<int>& nums,
//                vector<vector<int>>& dp) {
//         if (target == 0)
//             return true;
//         if (index == 0)
//             return (nums[0] == target);
//         if (dp[index][target] != -1) {
//             return dp[index][target];
//         }

//         bool notTake = solve(index - 1, target, nums, dp);
//         bool take = false;
//         if (nums[index] <= target) {
//             take = solve(index - 1, target - nums[index], nums, dp);
//         }

//         dp[index][target] = take || notTake;
//         return dp[index][target];
//     }

//     bool canPartition(vector<int>& nums) {
//         int n = nums.size();
//         int sum = accumulate(nums.begin(), nums.end(), 0);
//         vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

//         if (sum % 2 != 0)
//             return false;
//         else {
//             return solve(n - 1, sum / 2, nums, dp);
//         }
//     }
// };