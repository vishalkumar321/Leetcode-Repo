class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<pair<int, int>> ones;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    ones.push_back({i, j});
                }
            }
        }

        auto rectArea = [&](int r1, int c1, int r2, int c2) {
            if (r1 > r2 || c1 > c2) {
                return 0;
            }
            return (r2 - r1 + 1) * (c2 - c1 + 1);
        };

        auto getArea = [&](int r1, int c1, int r2, int c2) {
            int minr = n;
            int maxr = -1;
            int minc = m;
            int maxc = -1;

            for (auto& p : ones) {
                int r = p.first;
                int c = p.second;

                if (r1 <= r && r <= r2 && c1 <= c && c <= c2) {
                    minr = min(minr, r);
                    maxr = max(maxr, r);
                    minc = min(minc, c);
                    maxc = max(maxc, c);
                }
            }
            if (maxr == -1)
                return 0;
            return rectArea(minr, minc, maxr, maxc);
        };

        int ans = INT_MAX;

        for (int c1 = 0; c1 < m - 2; c1++) {
            for (int c2 = c1 + 1; c2 < m - 1; c2++) {
                int a1 = getArea(0, 0, n - 1, c1);
                int a2 = getArea(0, c1 + 1, n - 1, c2);
                int a3 = getArea(0, c2 + 1, n - 1, m - 1);
                if (a1 && a2 && a3) {
                    ans = min(ans, a1 + a2 + a3);
                }
            }
        }

        for (int r1 = 0; r1 < n - 2; r1++) {
            for (int r2 = r1 + 1; r2 < n - 1; r2++) {
                int a1 = getArea(0, 0, r1, m - 1);
                int a2 = getArea(r1 + 1, 0, r2, m - 1);
                int a3 = getArea(r2 + 1, 0, n - 1, m - 1);
                if (a1 && a2 && a3)
                    ans = min(ans, a1 + a2 + a3);
            }
        }

        for (int r = 0; r < n - 1; r++) {
            for (int c = 0; c < m - 1; c++) {
                int a1 = getArea(0, 0, r, m - 1);
                int a2 = getArea(r + 1, 0, n - 1, c);
                int a3 = getArea(r + 1, c + 1, n - 1, m - 1);
                if (a1 && a2 && a3)
                    ans = min(ans, a1 + a2 + a3);

                a1 = getArea(0, 0, n - 1, c);
                a2 = getArea(0, c + 1, r, m - 1);
                a3 = getArea(r + 1, c + 1, n - 1, m - 1);
                if (a1 && a2 && a3)
                    ans = min(ans, a1 + a2 + a3);

                a1 = getArea(0, c + 1, n - 1, m - 1);
                a2 = getArea(0, 0, r, c);
                a3 = getArea(r + 1, 0, n - 1, c);
                if (a1 && a2 && a3)
                    ans = min(ans, a1 + a2 + a3);

                a1 = getArea(r + 1, 0, n - 1, m - 1);
                a2 = getArea(0, 0, r, c);
                a3 = getArea(0, c + 1, r, m - 1);
                if (a1 && a2 && a3)
                    ans = min(ans, a1 + a2 + a3);
            }
        }

        return ans;
    }
};