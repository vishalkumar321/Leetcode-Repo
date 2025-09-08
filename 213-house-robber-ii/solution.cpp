// SPACE OPTIMIZATION APPROACH
class Solution {
public:
    int solve(vector<int>& nums, int start, int end) {
        int prev2 = 0;
        int prev1 = nums[start];

        for (int i = start + 1; i <= end; i++) {
            int include = prev2 + nums[i];
            int exclude = prev1;

            int curr = max(include, exclude);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        int case1 = solve(nums, 0, n - 2);
        int case2 = solve(nums, 1, n - 1);
        return max(case1, case2);
    }
};

// BOTTOM-UP APPROACH
// class Solution {
// public:
//     int solve(vector<int>& nums, int start, int end) {
//         if (start == end) {
//             return nums[start];
//         }

//         vector<int> dp(end - start + 1);
//         dp[0] = nums[start];
//         dp[1] = max(nums[start], nums[start + 1]);

//         for (int i = 2; i <= end - start; i++) {
//             int include = dp[i - 2] + nums[start + i];
//             int exclude = dp[i - 1];
//             dp[i] = max(include, exclude);
//         }
//         return dp[end - start];
//     }
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 0) return 0;
//         if (n == 1) return nums[0];
//         int case1 = solve(nums, 0, n - 2);
//         int case2 = solve(nums, 1, n - 1);

//         return max(case1, case2);
//     }
// };

// TOP-DOWN APPROACH
// class Solution {
// public:
//     int solve(vector<int>& nums, int n, int end, vector<int>& dp) {
//         if (n > end) {
//             return 0;
//         }
//         if (n == end) {
//             return nums[end];
//         }
//         if (dp[n] != -1) {
//             return dp[n];
//         }

//         int include = solve(nums, n+2, end, dp) + nums[n];
//         int exclude = solve(nums, n+1, end, dp);
//         dp[n] = max(include, exclude);
//         return dp[n];
//     }
//     int rob(vector<int>& nums) {
//         int n = nums.size();

//         if (n == 0)
//             return 0;
//         if (n == 1)
//             return nums[0];

//         vector<int> dp1(n + 1, -1);
//         int case1 = solve(nums, 0, n - 2, dp1);

//         vector<int> dp2(n + 1, -1);
//         int case2 = solve(nums, 1, n - 1, dp2);

//         return max(case1, case2);
//     }
// };