class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        int count = 0;

        // Populate the dp matrix
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                // Only proceed if current cell is a '1'
                if (matrix[i][j] == 1) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1; // Edge cases for first row/column
                    } else {
                        dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    }
                    count += dp[i][j]; // Add the square count ending at (i, j)
                }
            }
        }
        return count;
    }
};
