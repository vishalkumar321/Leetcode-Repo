// SPACE OPTIMIZATION APPROACH
class Solution {
public:
    int solve(vector<int>& nums, int n) {
        int prev2 = 0;
        int prev1 = nums[0];

        for (int i = 1; i < n; i++) {
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

        return solve(nums, n);
    }
};

// BOTTOM UP APPROACH
// class Solution {
// public:
//     int solve(vector<int>& nums, int n) {
//         if(n==1) return nums[0];
//         vector<int> dp(n, 0);

//         dp[0] = nums[0];
//         dp[1] = max(nums[0],nums[1]);

//         for (int i = 2; i < n; i++) {
//             int include = dp[i - 2] + nums[i];
//             int exclude = dp[i - 1];
//             dp[i] = max(include, exclude);
//         }
//         return dp[n-1];
//     }

//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         return solve(nums, n);
//     }
// };

// TOP DOWN APPROACH
// class Solution {
// public:
//     int solve(vector<int>& nums, int n, vector<int>& dp) {
//         if (n < 0)
//             return 0;
//         if (n == 0)
//             return nums[0];

//         if(dp[n] != -1) return dp[n];

//         int include = solve(nums, n - 2, dp) + nums[n];
//         int exclude = solve(nums, n - 1, dp);

//         dp[n] = max(include, exclude);
//         return dp[n];
//     }
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n, -1);

//         return solve(nums, n - 1, dp);
//     }
// };