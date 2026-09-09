class Solution {
public:
    int solve(int idx, vector<int>& arr, int k, int n, vector<int>& dp) {
        if (idx >= n)
            return 0;

        if (dp[idx] != -1) {
            return dp[idx];
        }

        int currMax = 0;
        int ans = 0;

        int end = min(n, idx + k);
        for (int i = idx; i < end; i++) {
            currMax = max(currMax, arr[i]);
            ans =
                max(ans, currMax * (i - idx + 1) + solve(i + 1, arr, k, n, dp));
        }
        dp[idx] = ans;
        return dp[idx];
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        vector<int> dp(n, -1);
        return solve(0, arr, k, n, dp);
    }
};