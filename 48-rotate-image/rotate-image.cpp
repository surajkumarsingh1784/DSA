class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
           int m = matrix.size();
        int n = m;
        // 1st transpose - row ->column
        for (int i = 0; i < m; i++) {
            for (int j = i; j < n; j++) { // j start from i, swap diagnoally
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // 2nd - reverse each row
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};