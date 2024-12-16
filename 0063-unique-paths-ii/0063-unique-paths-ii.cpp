class Solution {
public:
    int findans(int i, int j, vector<vector<int>>& dp, int m, int n, vector<vector<int>>& grid) {
        // Base cases
        if (i >= m || j >= n || grid[i][j] == 1) {
            return 0; // Out of bounds or obstacle
        }
        if (i == m-1 && j == n-1) {
            return 1; // Reached destination
        }
        if (dp[i][j] != -1) {
            return dp[i][j]; // Return cached result
        }

        // Recursive calls
        dp[i][j] = findans(i+1, j, dp, m, n, grid) + findans(i, j+1, dp, m, n, grid);
        return dp[i][j];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        // Initialize DP table
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        // Call the helper function starting at the top-left corner
        return findans(0, 0, dp, m, n, obstacleGrid);
    }
};
