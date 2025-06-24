class Solution {
public:
    int solve(const vector<int>& v, int x, int i, vector<vector<int>>& dp) {
        if (i >= v.size()) return 0;
        if (x < 0) return 0;
        if (x == 0) return 1;
        if (dp[i][x] != -1) return dp[i][x];
        
        int op1 = solve(v, x, i + 1, dp);
        int op2 = solve(v, x - v[i], i, dp);
        return dp[i][x] = op1 + op2;
    }

    vector<int> findCoins(vector<int>& numWays) {
        vector<int> v;
        bool flag = true;

        for (int i = 0; i < numWays.size(); ++i) {
            if (v.empty() && numWays[i] == 1) {
                v.push_back(i + 1);
            } else if (v.empty() && numWays[i] > 1) {
                return {};
            } else {
                int target = i + 1;
                int maxX = target;

                vector<vector<int>> dp(v.size(), vector<int>(maxX + 1, -1));
                int a = solve(v, target, 0, dp);

                if (a < numWays[i]) {
                    v.push_back(i + 1);
                    dp = vector<vector<int>>(v.size(), vector<int>(maxX + 1, -1));
                    a = solve(v, target, 0, dp);
                }

                if (a != numWays[i]) {
                    flag = false;
                    break;
                }
            }
        }

        return flag ? v : vector<int>();
    }
};