class Solution {
public:
    bool checkSpecial(int row, int col, int n, int m,
                      vector<vector<int>>& mat) {

        for (int i = 0; i < n; i++) {
            if (i == row)
                continue;
            else if (mat[i][col] == 1)
                return false;
        }

        for (int j = 0; j < m; j++) {
            if (j == col)
                continue;
            else if (mat[row][j] == 1)
                return false;
        }
        return true;
    }

    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    if (checkSpecial(i, j, n, m, mat))
                        count++;
                }
            }
        }
        return count;
    }
};