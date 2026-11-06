class Solution {
    public int helper(int idx, int[] nums, int[] dp) {
        if (idx < 0) {
            return 0;
        }

        if (idx == 0) {
            return nums[idx];
        }

        if (dp[idx] != -1) {
            return dp[idx];
        }

        int notTake = helper(idx - 1, nums, dp);
        int take = nums[idx] + helper(idx - 2, nums, dp);

        dp[idx] = Math.max(take, notTake);
        return dp[idx];
    }

    public int rob(int[] nums) {
        int n = nums.length;

        int[] dp = new int[n];
        Arrays.fill(dp, -1);

        return helper(n - 1, nums, dp);
    }
}