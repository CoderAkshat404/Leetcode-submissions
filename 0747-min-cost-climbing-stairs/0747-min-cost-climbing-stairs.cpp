class Solution {
public:
    int findans(vector<int>& dp, int i, vector<int>& cost) {
        int n = cost.size();
        // Base case: Reaching the "top" (beyond the last index)
        if (i >= n) {
            return 0;  // No cost incurred at the "top"
        }
        // Check memoized results
        if (dp[i] != -1) {
            return dp[i];
        }
        // Recurrence relation: Pick current cost and jump 1 or 2 steps
        dp[i] = cost[i] + min(findans(dp, i + 1, cost), findans(dp, i + 2, cost));
        return dp[i];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);  // Memoization table

        // Start from step 0 or step 1 and find the minimum cost
        return min(findans(dp, 0, cost), findans(dp, 1, cost));
    }
};
