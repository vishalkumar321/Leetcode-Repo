class Solution {
public:
    int helper(int idx, int n, vector<int>& costs, vector<int>& dp) {
        if (idx == n) {
            return 0;
        }

        if (dp[idx] != -1) {
            return dp[idx];
        }

        int ans = INT_MAX;
        for (int jump = 1; jump <= 3; jump++) {
            int next = idx + jump;

            if (next <= n) {
                int currCost = costs[next - 1] + jump * jump;
                ans = min(ans, currCost + helper(next, n, costs, dp));
            }
        }
        dp[idx] = ans;
        return dp[idx];
    }

    int climbStairs(int n, vector<int>& costs) {

        vector<int> dp(n + 1, -1);
        return helper(0, n, costs, dp);
    }
};