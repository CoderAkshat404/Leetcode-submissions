class Solution {
public:
    int n;
    int dp[1001];
    int f(string &s, int k, int i) {
        if(i == 0)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        // take
        int x = 0;
        if((s[i-1]-'0')*pow(2, n-i) <= k)
            x = 1 + f(s, k-(s[i-1]-'0')*pow(2, n-i), i-1);
        // not take
        int y = f(s, k, i-1);
        return dp[i] = max(x, y);
    }
    int longestSubsequence(string &s, int k) {
        n = s.length();
        memset(dp, -1, sizeof(dp));
        return f(s, k, n);
    }
};