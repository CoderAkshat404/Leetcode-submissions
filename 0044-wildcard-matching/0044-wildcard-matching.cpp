class Solution {
public:
    bool findans(int i, int j, string s, string p, vector<vector<int>>&dp) {
        // Base case: both strings are fully matched
        if (i == s.length() && j == p.length()) {
            return true;
        }
        // Case: `p` is fully traversed, but `s` still has characters
        if (i < s.length() && j == p.length()) {
            return false;
        }
        // Case: `s` is fully traversed, but `p` still has characters
        if (i == s.length() && j < p.length()) {
            // Check if the remaining characters in `p` are all '*'
            for (int k = j; k < p.length(); k++) {
                if (p[k] != '*') {
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        // Case: current characters match or pattern has `?`
        if (i < s.length() && j < p.length() && (s[i] == p[j] || p[j] == '?')) {
            return dp[i][j]=findans(i + 1, j + 1, s, p,dp);
        }
        // Case: pattern has `*`
        if (p[j] == '*') {
            // Try two possibilities:
            // 1. Skip the `*` (move to the next character in `p`).
            // 2. Use `*` to match the current character in `s` (move to the next character in `s`).
            return dp[i][j]=findans(i, j + 1, s, p,dp) || (i < s.length() && findans(i + 1, j, s, p,dp));
        }
        // Case: characters do not match
        return dp[i][j]=false;
    }
    
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return findans(0, 0, s, p,dp);
    }
};
