class Solution {
public:
    int rec(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& grid, int n, int m) {
        // Base case: If we reach the bottom-right corner, return the value
        if (i == n - 1 && j == m - 1) {
            return grid[i][j];
        }
        // If out of bounds, return a large number
        else if (i >= n || j >= m) {
            return INT_MAX;
        }

        // If the value is already computed, return it
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Recursively find the minimum path sum
        dp[i][j] = grid[i][j] + min(rec(i + 1, j, dp, grid, n, m), rec(i, j + 1, dp, grid, n, m));
        return dp[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Initialize DP table with -1
        vector<vector<int>> dp(n, vector<int>(m, -1));

        // Start recursion from the top-left corner (0, 0)
        return rec(0, 0, dp, grid, n, m);
    }
};
