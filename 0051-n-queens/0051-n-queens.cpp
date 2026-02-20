class Solution {
public:
    bool isSafe(vector <string>& board, int row, int col) {
        // col
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }

        // main diag
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // anti diag
        for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    void solve(int n, vector <string>& board, int row, vector <vector <string>>& ans) {
        if (row == n){
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col)) {
                board[row][col] = 'Q';
                solve(n, board, row + 1, ans);
                board[row][col] = '.'; // beautiful
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector <string> board(n, string(n, '.'));
        vector <vector <string>> ans;

        solve(n, board, 0, ans);

        return ans;
    }
};