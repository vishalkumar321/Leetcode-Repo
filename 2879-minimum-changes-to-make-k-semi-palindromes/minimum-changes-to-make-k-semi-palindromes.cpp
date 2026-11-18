class Solution {
    int getCost(string& s, int start, int len,
                vector<vector<int>>& divisors) {

        int ans = len;

        for (int d : divisors[len]) {

            int groups = len / d;
            int changes = 0;

            for (int i = 0; i < d; i++) {

                for (int j = 0; j < groups / 2; j++) {

                    int left = start + i + j * d;
                    int right = start + i + (groups - 1 - j) * d;

                    if (s[left] != s[right]) {
                        changes++;
                    }
                }
            }

            ans = min(ans, changes);
        }

        return ans;
    }

public:
    int minimumChanges(string s, int k) {

        int n = s.size();

        vector<vector<int>> divisors(n + 1);

        for (int d = 1; d <= n / 2; d++) {
            for (int len = 2 * d; len <= n; len += d) {
                divisors[len].push_back(d);
            }
        }

        vector<vector<int>> cost(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                cost[i][j] = getCost(s, i, j - i + 1, divisors);
            }
        }

        vector<int> prev(n, 0);

        for (int i = 0; i < n; i++) {
            prev[i] = cost[i][n - 1];
        }

        for (int seg = 2; seg <= k; seg++) {

            vector<int> curr(n, n);

            int limit = n - 1 - 2 * (seg - 1);

            for (int start = 0; start + 2 * seg <= n; start++) {

                for (int end = start + 1; end <= limit; end++) {

                    curr[start] = min(
                        curr[start],
                        cost[start][end] + prev[end + 1]
                    );
                }
            }

            prev.swap(curr);
        }

        return prev[0];
    }
};