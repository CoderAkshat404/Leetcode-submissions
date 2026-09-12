class Solution {
public:
    vector<vector<pair<long long, vector<int>>>> dp;
    vector<vector<bool>> vis;

    pair<long long, vector<int>> solve(int i, int taken, vector<vector<int>>& intervals) {
        if (taken == 4 || i >= intervals.size()) {
            return {0LL, {}};
        }

        if (vis[i][taken]) {
            return dp[i][taken];
        }

        vis[i][taken] = true;

        int next = upper_bound(
            intervals.begin(),
            intervals.end(),
            intervals[i][1],
            [](int end, const vector<int>& interval) {
                return end < interval[0];
            }
        ) - intervals.begin();

        // Don't take
        pair<long long, vector<int>> nottake =
            solve(i + 1, taken, intervals);

        // Take
        pair<long long, vector<int>> take =
            solve(next, taken + 1, intervals);

        vector<int> v = take.second;
        v.push_back(intervals[i][3]);
        sort(v.begin(), v.end());

        long long score = take.first + (long long)intervals[i][2];

        if (score > nottake.first) {
            dp[i][taken] = {score, v};
        }
        else if (score < nottake.first) {
            dp[i][taken] = nottake;
        }
        else {
            if (v < nottake.second) {
                dp[i][taken] = {score, v};
            }
            else {
                dp[i][taken] = nottake;
            }
        }

        return dp[i][taken];
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }

        sort(intervals.begin(), intervals.end());

        dp.resize(n, vector<pair<long long, vector<int>>>(4));
        vis.assign(n, vector<bool>(4, false));

        return solve(0, 0, intervals).second;
    }
};