class Solution {
public:
    const int MOD = 1e9 + 7;

    int solve(int zeros, int ones, int last, int streak, int limit,
              vector<vector<vector<vector<int>>>>& dp) {

        if (zeros == 0 && ones == 0)
            return 1;

        if (last != 2 && dp[zeros][ones][last][streak] != -1)
            return dp[zeros][ones][last][streak];

        long long ans = 0;

        if (zeros > 0) {
            if (last != 0)
                ans += solve(zeros - 1, ones, 0, 1, limit, dp);
            else if (streak < limit)
                ans += solve(zeros - 1, ones, 0, streak + 1, limit, dp);
        }

        if (ones > 0) {
            if (last != 1)
                ans += solve(zeros, ones - 1, 1, 1, limit, dp);
            else if (streak < limit)
                ans += solve(zeros, ones - 1, 1, streak + 1, limit, dp);
        }

        ans %= MOD;

        if (last != 2)
            dp[zeros][ones][last][streak] = ans;

        return ans;
    }

    int numberOfStableArrays(int zero, int one, int limit) {

        vector<vector<vector<vector<int>>>> dp(
            zero + 1,
            vector<vector<vector<int>>>(
                one + 1, vector<vector<int>>(2, vector<int>(limit + 1, -1))));

        return solve(zero, one, 2, 0, limit, dp);
    }
};