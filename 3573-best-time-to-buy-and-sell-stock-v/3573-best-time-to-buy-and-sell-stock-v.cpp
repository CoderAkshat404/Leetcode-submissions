class Solution {
public:
    long long maximumProfit(vector<int>& prices, int p) {
        int n = prices.size();

        vector<vector<vector<vector<long long>>>> dp(2, vector<vector<vector<long long>>>(
            n + 1, vector<vector<long long>>(2, vector<long long>(p + 1, 0))));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= 1; j++) {
                for (int k = 1; k <= p; k++) {
                    for (int l = 0; l <= 1; l++) {
                        if (l == 0) {
                            dp[l][i][j][k] = max({
                                dp[l][i + 1][j][k],                          // Do nothing
                                -prices[i] + dp[1][i + 1][1][k],             // Start normal (buy)
                                prices[i] + dp[1][i + 1][0][k]               // Start short (sell)
                            });
                        } else {
                            if (j == 0) {
                                dp[l][i][j][k] = max(
                                    -prices[i] + dp[0][i + 1][1][k - 1],     // Buy back (finish short)
                                    dp[l][i + 1][j][k]                       // Do nothing
                                );
                            } else {
                                dp[l][i][j][k] = max(
                                    prices[i] + dp[0][i + 1][0][k - 1],      // Sell (finish normal)
                                    dp[l][i + 1][j][k]                       // Do nothing
                                );
                            }
                        }
                    }
                }
            }
        }

        return dp[0][0][0][p];
    }
};