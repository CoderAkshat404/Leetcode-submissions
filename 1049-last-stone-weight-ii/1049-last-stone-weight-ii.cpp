class Solution {
public:
    int dp[31][3001];

    int solve(int i, int sum, vector<int>& stones) {
        if (sum == 0) return 1;
        if (sum < 0 || i >= stones.size()) return 0;

        if (dp[i][sum] != -1)
            return dp[i][sum];

        int take = solve(i + 1, sum - stones[i], stones);
        int nottake = solve(i + 1, sum, stones);

        return dp[i][sum] = take || nottake;
    }

    int lastStoneWeightII(vector<int>& stones) {
        int totalsum = 0;

        for (auto x : stones)
            totalsum += x;

        memset(dp, -1, sizeof(dp));

       int mini=1e9;

       for (int i = totalsum; i >= 0; i--) {
    if (solve(0, i, stones)) {
        mini = min(mini, abs(totalsum - 2 * i));
    }
}

        return mini;
    }
};