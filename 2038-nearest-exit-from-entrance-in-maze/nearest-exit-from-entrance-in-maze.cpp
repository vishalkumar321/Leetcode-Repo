class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        visited[entrance[0]][entrance[1]] = true;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        int nearExit = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [row, col] = q.front();
                q.pop();

                if ((row == 0 || row == n - 1 || col == 0 || col == m - 1) &&
                    !(row == entrance[0] && col == entrance[1])) {
                    return nearExit;
                }

                for (int i = 0; i < 4; i++) {
                    int nrow = row + delRow[i];
                    int ncol = col + delCol[i];

                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                        maze[nrow][ncol] == '.' && !visited[nrow][ncol]) {

                        q.push({nrow, ncol});
                        visited[nrow][ncol] = true;
                    }
                }
            }
            nearExit++;
        }
        return -1;
    }
};