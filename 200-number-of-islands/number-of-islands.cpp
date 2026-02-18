class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == '1') {
                    q.push({i, j});
                    grid[i][j] = '0';

                    while (!q.empty()) {
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();

                        int delRow[] = {1, 0, -1, 0};
                        int delCol[] = {0, 1, 0, -1};

                        for (int i = 0; i < 4; i++) {
                            int nrow = row + delRow[i];
                            int ncol = col + delCol[i];

                            if (nrow >= 0 && nrow < n && ncol >= 0 &&
                                ncol < m && grid[nrow][ncol] == '1') {
                                grid[nrow][ncol] = 0;
                                q.push({nrow, ncol});
                            }
                        }
                    }
                    ans++;
                }
            }
        }

        return ans;
    }
};