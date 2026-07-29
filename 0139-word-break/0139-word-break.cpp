class Solution {
public:
    vector<vector<int>> dp;

    bool solve(int start, int i, string &s, set<string> &st) {
        if (start == s.length())
            return true;

        if (i == s.length())
            return false;

        if (dp[start][i] != -1)
            return dp[start][i];

        bool flag = false;

        string temp = s.substr(start, i - start + 1);

        if (st.find(temp) != st.end()) {
            flag = flag || solve(i + 1, i + 1, s, st);
        }

        flag = flag || solve(start, i + 1, s, st);

        return dp[start][i] = flag;
    }

    bool wordBreak(string s, vector<string> &wordDict) {
        set<string> st(wordDict.begin(), wordDict.end());
        int n = s.size();
        dp.assign(n + 1, vector<int>(n + 1, -1));
        return solve(0, 0, s, st);
    }
};