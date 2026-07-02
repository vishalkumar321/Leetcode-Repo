class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        deque<pair<int, int>> dq;

        dq.push_front({0, 0});

        dist[0][0] = grid[0][0];

        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};

        while (!dq.empty()) {
            int row = dq.front().first;
            int col = dq.front().second;
            dq.pop_front();

            if (row == n - 1 && col == m - 1) {
                return true;
            }

            for (int i = 0; i < 4; i++) {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= m)
                    continue;

                int newCost = dist[row][col] + grid[nrow][ncol];

                if (newCost >= health)
                    continue;

                if (newCost < dist[nrow][ncol]) {
                    dist[nrow][ncol] = newCost;

                    if (grid[nrow][ncol] == 0) {
                        dq.push_front({nrow, ncol});
                    } else {
                        dq.push_back({nrow, ncol});
                    }
                }
            }
        }
        return false;
    }
};