class Solution {
    public int orangesRotting(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        Queue<int[]> q = new LinkedList<>();
        boolean[][] visited = new boolean[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.add(new int[] { i, j, 0 });
                    visited[i][j] = true;
                }
            }
        }

        int minute = 0;
        while (!q.isEmpty()) {
            int[] node = q.poll();

            int row = node[0];
            int col = node[1];
            int step = node[2];

            minute = Math.max(minute, step);
            int[] delRow = { 0, 1, 0, -1 };
            int[] delCol = { 1, 0, -1, 0 };

            for (int i = 0; i < 4; i++) {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1 && !visited[nrow][ncol]) {
                    q.add(new int[] { nrow, ncol, step + 1 });
                    visited[nrow][ncol] = true;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    return -1;
                }
            }
        }
        return minute;
    }
}