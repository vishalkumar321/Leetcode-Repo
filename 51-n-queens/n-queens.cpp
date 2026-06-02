class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col, int n) {

        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        for (int j = 0; j < n; j++) {
            if (board[row][j] == 'Q') {
                return false;
            }
        }

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void helper(vector<vector<string>>& ans, vector<string>& board, int row,
                int n) {

        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (isSafe(board, row, i, n)) {
                board[row][i] = 'Q';
                helper(ans, board, row + 1, n);
                board[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        helper(ans, board, 0, n);
        return ans;
    }
};