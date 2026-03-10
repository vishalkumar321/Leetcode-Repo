class Solution {
public:
    int MOD = 1e9 + 7;
    vector<vector<vector<int>>> dp;

    int solve(int zero, int one, int lastBit, int limit) {

        if (zero == 0) {
            if (lastBit == 0 || one > limit)
                return 0;
            return 1;
        }

        if (one == 0) {
            if (lastBit == 1 || zero > limit)
                return 0;
            return 1;
        }

        if (dp[zero][one][lastBit] != -1)
            return dp[zero][one][lastBit];

        long long result = 0;

        if (lastBit == 0) {

            result = (solve(zero - 1, one, 0, limit) +
                      solve(zero - 1, one, 1, limit)) %
                     MOD;

            if (zero > limit) {
                result =
                    (result - solve(zero - limit - 1, one, 1, limit) + MOD) %
                    MOD;
            }

        } else {

            result = (solve(zero, one - 1, 0, limit) +
                      solve(zero, one - 1, 1, limit)) %
                     MOD;

            if (one > limit) {
                result =
                    (result - solve(zero, one - limit - 1, 0, limit) + MOD) %
                    MOD;
            }
        }

        return dp[zero][one][lastBit] = result;
    }

    int numberOfStableArrays(int zero, int one, int limit) {

        dp.assign(zero + 1, vector<vector<int>>(one + 1, vector<int>(2, -1)));

        return (solve(zero, one, 0, limit) + solve(zero, one, 1, limit)) % MOD;
    }
};