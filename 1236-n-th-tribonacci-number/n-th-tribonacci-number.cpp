class Solution {
public:
    int tribonacci_helper(int n, vector<int>& dp) {
        if (n <= 1) {
            return n;
        } else if (n == 2) {
            return 1;
        }
        if (dp[n] != -1) {
            return dp[n];
        }

        dp[n] = tribonacci_helper(n - 1, dp) + tribonacci_helper(n - 2, dp) +
                tribonacci_helper(n - 3, dp);
        return dp[n];
    }

    int tribonacci(int n) {
        vector<int> dp(n + 1, -1);
        return tribonacci_helper(n, dp);
    }
};