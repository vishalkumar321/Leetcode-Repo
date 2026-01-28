class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<pair<int, int>> cells;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cells.push_back({i, j});
            }
        }

        sort(cells.begin(), cells.end(),
             [&](pair<int, int>& a, pair<int, int>& b) {
                 return grid[a.first][a.second] < grid[b.first][b.second];
             });

        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));

        for (int step = 0; step <= k; step++) {
            int best = INT_MAX;
            int start = 0;

            for (int i = 0; i < cells.size(); i++) {
                int r = cells[i].first;
                int c = cells[i].second;

                best = min(best, cost[r][c]);

                if (i + 1 < cells.size() &&
                    grid[cells[i].first][cells[i].second] ==
                        grid[cells[i + 1].first][cells[i + 1].second]) {
                    continue;
                }

                for (int j = start; j <= i; j++) {
                    cost[cells[j].first][cells[j].second] = best;
                }

                start = i + 1;
            }

            for (int i = m - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {
                    if (i == m - 1 && j == n - 1) {
                        cost[i][j] = 0;
                        continue;
                    }

                    if (i + 1 < m) {
                        cost[i][j] =
                            min(cost[i][j], cost[i + 1][j] + grid[i + 1][j]);
                    }

                    if (j + 1 < n) {
                        cost[i][j] =
                            min(cost[i][j], cost[i][j + 1] + grid[i][j + 1]);
                    }
                }
            }
        }

        return cost[0][0];
    }
};
