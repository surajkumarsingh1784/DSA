class Solution {
public:
    bool row[9][9] = {false};
    bool col[9][9] = {false};
    bool box[9][9] = {false};

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {

                    for (char c = '1'; c <= '9'; c++) {
                        int num = c - '1';
                        int b = (i / 3) * 3 + (j / 3);

                        if (!row[i][num] && !col[j][num] && !box[b][num]) {
                            board[i][j] = c;
                            row[i][num] = col[j][num] = box[b][num] = true;

                            if (solve(board)) return true;

                            // backtrack
                            board[i][j] = '.';
                            row[i][num] = col[j][num] = box[b][num] = false;
                        }
                    }
                    return false; // no valid number
                }
            }
        }
        return true; // solved
    }

    void solveSudoku(vector<vector<char>>& board) {
        // initial fill
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    int b = (i / 3) * 3 + (j / 3);
                    row[i][num] = col[j][num] = box[b][num] = true;
                }
            }
        }
        solve(board);
    }
};
