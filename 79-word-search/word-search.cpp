class Solution {
public:
   bool dfs(vector<vector<char>>& board, int i, int j, string& word, int idx) {
    // Base case: all characters matched
    if (idx == word.size()) return true;

    // Out of bounds or character mismatch
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[idx])
        return false;

    // Mark visited
    char temp = board[i][j];
    board[i][j] = '#';

    // Explore 4 directions (up, down, left, right)
    bool found = dfs(board, i + 1, j, word, idx + 1) ||
                 dfs(board, i - 1, j, word, idx + 1) ||
                 dfs(board, i, j + 1, word, idx + 1) ||
                 dfs(board, i, j - 1, word, idx + 1);
    board[i][j] = temp;

    return found;
}

bool exist(vector<vector<char>>& board, string word) {
    int m = board.size(), n = board[0].size();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // Start DFS from the first matching character
            if (board[i][j] == word[0] && dfs(board, i, j, word, 0))
                return true;
        }
    }
    return false;
}
};