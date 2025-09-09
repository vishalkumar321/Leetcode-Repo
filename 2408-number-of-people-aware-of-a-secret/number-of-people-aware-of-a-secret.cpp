class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0);
        
        dp[1] = 1;

        for (int day = 1; day <= n; day++) {
            for (int next = day + delay; next < day + forget && next <= n;
                 next++) {
                dp[next] = (dp[next] + dp[day]) % MOD;
            }
        }

        long long ans = 0;
        for (int day = n - forget + 1; day <= n; day++) {
            if (day >= 1)
                ans = (ans + dp[day]) % MOD;
        }
        return ans;
    }
};
