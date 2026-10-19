class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int r = 0;
        int c = 0;

        visited[r][c] = true;

        while (true) {
            int nr = r;
            int nc = c;

            if (grid[nr][nc] == 'L') {
                nc--;
            } else if (grid[nr][nc] == 'R') {
                nc++;
            } else if (grid[nr][nc] == 'U') {
                nr--;
            } else if (grid[nr][nc] == 'D') {
                nr++;
            }

            if (nr < 0 || nc < 0 || nr >= m || nc >= n || visited[nr][nc]) {
                break;
            }

            r = nr;
            c = nc;
            visited[r][c] = true;
        }
        return {r, c};
    }
};