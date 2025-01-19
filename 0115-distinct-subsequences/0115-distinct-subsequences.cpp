class Solution {
public:
    int numDistinct(string s, string t) {
        const int MOD = 1e9 + 7; // Define the modulo value
        int n = s.length();
        int m = t.length();
        
        // Use a 2D DP table to store the results
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
        
        // Base case: If `t` is empty, there's exactly 1 way to match it
        for (int i = 0; i <= n; i++) {
            dp[i][m] = 1;
        }
        
        // Fill the DP table bottom-up
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s[i] == t[j]) {
                    dp[i][j] = (dp[i + 1][j + 1] + dp[i + 1][j]) % MOD;
                } else {
                    dp[i][j] = dp[i + 1][j] % MOD;
                }
            }
        }
        
        // Return the result modulo MOD
        return dp[0][0] % MOD;
    }
};
