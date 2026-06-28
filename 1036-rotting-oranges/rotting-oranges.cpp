class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = true;
                }
            }
        }

        int minute = 0;
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int step = q.front().second;
            q.pop();

            minute = max(step, minute);

            int delRow[4] = {-1, 0, 1, 0};
            int delCol[4] = {0, -1, 0, 1};

            for (int i = 0; i < 4; i++) {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == 1 && !visited[nrow][ncol]) {
                    visited[nrow][ncol] = true;
                    q.push({{nrow, ncol}, step + 1});
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return minute;
    }
};