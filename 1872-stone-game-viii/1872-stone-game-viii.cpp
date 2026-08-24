class Solution {
public:
    int dp[100100];
    int n;
    vector<int> pre;
    int solve(int i) {
    if (i >= n) return 0;
    if (dp[i] != -1) return dp[i];
    if (i == n - 1) return dp[i] = pre[i]; 
    int nxt = solve(i + 1);
    return dp[i] = max(pre[i] - nxt, nxt);
}

    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();
        pre.resize(n);
        pre[0] = stones[0];
        for (int i = 1; i < n; i++) pre[i] = pre[i-1] + stones[i];
        memset(dp, -1, sizeof(dp));
        return solve(1);
    }
};