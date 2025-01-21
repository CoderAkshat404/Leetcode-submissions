class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        if (n == 1) return 0; // No movement possible with a single column.

        vector<long long> pre1(n), pre2(n);
        
        // Calculate prefix sums for row 1 and row 2
        pre1[0] = grid[0][0];
        pre2[0] = grid[1][0];
        for (int i = 1; i < n; i++) {
            pre1[i] = pre1[i - 1] + grid[0][i];
            pre2[i] = pre2[i - 1] + grid[1][i];
        }

        long long mini = LLONG_MAX;

        // Determine the minimum possible maximum score
        for (int i = 0; i < n; i++) {
            long long sl = (i == 0) ? 0 : pre2[i - 1]; // Sum left in row 2
            long long s1 = (i == n - 1) ? 0 : pre1[n - 1] - pre1[i]; // Sum left in row 1
            long long maxi = max(sl, s1);
            mini = min(maxi, mini);
        }

        return mini;
    }
};
