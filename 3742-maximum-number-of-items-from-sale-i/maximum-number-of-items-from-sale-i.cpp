class Solution {
public:
    int solve(vector<int>& price, vector<int>& cnt, int index,
              int budget, vector<vector<int>>& dp) {

        if (index == price.size()) {
            return 0;
        }

        if (dp[index][budget] != -1) {
            return dp[index][budget];
        }

        int notTake = solve(price, cnt, index + 1, budget, dp);

        int take = 0;

        if (price[index] <= budget) {
            take = cnt[index] + solve(price, cnt, index + 1,
                                      budget - price[index], dp);
        }

        return dp[index][budget] = max(take, notTake);
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> price(n);
        vector<int> cnt(n);

        int mn = INT_MAX;

        for (int i = 0; i < n; i++) {
            price[i] = items[i][1];
            mn = min(mn, price[i]);
        }

        for (int i = 0; i < n; i++) {
            int factor = items[i][0];

            for (int j = 0; j < n; j++) {
                if (items[j][0] % factor == 0) {
                    cnt[i]++;
                }
            }
        }

        vector<vector<int>> dp(n, vector<int>(budget + 1, -1));

        int ans = 0;

        for (int b = 0; b <= budget; b++) {
            int result = solve(price, cnt, 0, b, dp);

            ans = max(ans, result + (budget - b) / mn);
        }

        return ans;
    }
};