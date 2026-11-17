class Solution {
public:
    long long solve(int idx, vector<int>& nums, int n, vector<long long>& dp) {
        if (idx == n) {
            return 0;
        }

        if (dp[idx] != LLONG_MIN) {
            return dp[idx];
        }

        long long choice1 = LLONG_MIN;
        long long sum1 = nums[idx];

        if (sum1 % 3 == 0) {
            choice1 = sum1 - solve(idx + 1, nums, n, dp);
        } else {
            choice1 = sum1 + solve(idx + 1, nums, n, dp);
        }

        long long choice2 = LLONG_MIN;

        if (idx + 1 < n) {
            long long sum2 = nums[idx] + nums[idx + 1];

            if (sum2 % 3 == 0) {
                choice2 = sum2 - solve(idx + 2, nums, n, dp);
            } else {
                choice2 = sum2 + solve(idx + 2, nums, n, dp);
            }
        }
        dp[idx] = max(choice1, choice2);
        return dp[idx];
    }

    long long maxDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> dp(n, LLONG_MIN);
        return solve(0, nums, n, dp);
    }
};