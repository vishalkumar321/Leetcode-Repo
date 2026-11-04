class Solution {
    public int numIslands(char[][] grid) {

        int m = grid.length;
        int n = grid[0].length;

        int island = 0;
        boolean[][] visited = new boolean[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == '1' && !visited[i][j]) {
                    Queue<int[]> q = new LinkedList<>();
                    q.add(new int[] { i, j });
                    visited[i][j] = true;

                    while (!q.isEmpty()) {
                        int[] node = q.poll();

                        int row = node[0];
                        int col = node[1];

                        int[] delRow = { 1, -1, 0, 0 };
                        int[] delCol = { 0, 0, 1, -1 };

                        for (int k = 0; k < 4; k++) {
                            int nrow = row + delRow[k];
                            int ncol = col + delCol[k];

                            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == '1'
                                    && !visited[nrow][ncol]) {
                                q.add(new int[] { nrow, ncol });
                                visited[nrow][ncol] = true;
                            }
                        }
                    }
                    island++;
                }
            }
        }
        return island;
    }
}