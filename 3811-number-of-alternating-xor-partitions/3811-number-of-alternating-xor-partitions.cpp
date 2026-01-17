class Solution {
public:
    static const int mod = 1000000007;
    vector<vector<vector<int>>> dp;

    int solve(int i, int n, int target1, int target2, int s, vector<int>& pre, int curr) {
        if (i == n - 1) {
            int x = target1;
            if (s == 1) x = target2;

            if (curr == 0) {
                if ((pre[i] ^ 0) == x) return 1;
            }
            else if (curr == 1) {
                if ((pre[i] ^ target1) == x) return 1;
            }
            else if (curr == 2) {
                if (((pre[i] ^ target1) ^ target2) == x) return 1;
            }
            else if (curr == 3) {
                if ((pre[i] ^ target2) == x) return 1;
            }
            return 0;
        }

        if (dp[i][s][curr] != -1)
            return dp[i][s][curr];

        long long ans = 0;
        int x = target1;
        if (s == 1) x = target2;

        if (curr == 0) {
            if ((pre[i] ^ 0) == x)
                ans = (ans + solve(i + 1, n, target1, target2, 1 - s, pre, 1)) % mod;
        }
        else if (curr == 1) {
            if ((pre[i] ^ target1) == x)
                ans = (ans + solve(i + 1, n, target1, target2, 1 - s, pre, 2)) % mod;
        }
        else if (curr == 2) {
            if (((pre[i] ^ target1) ^ target2) == x)
                ans = (ans + solve(i + 1, n, target1, target2, 1 - s, pre, 3)) % mod;
        }
        else if (curr == 3) {
            if ((pre[i] ^ target2) == x)
                ans = (ans + solve(i + 1, n, target1, target2, 1 - s, pre, 0)) % mod;
        }

        ans = (ans + solve(i + 1, n, target1, target2, s, pre, curr)) % mod;

        return dp[i][s][curr] = (int)ans;
    }

    int alternatingXOR(vector<int>& nums, int target1, int target2) {
        int n = nums.size();
        int xori = 0;
        vector<int> pre(n);

        for (int i = 0; i < n; i++) {
            xori ^= nums[i];
            pre[i] = xori;
        }

        dp.assign(n, vector<vector<int>>(2, vector<int>(4, -1)));

        return solve(0, n, target1, target2, 0, pre, 0);
    }
};
