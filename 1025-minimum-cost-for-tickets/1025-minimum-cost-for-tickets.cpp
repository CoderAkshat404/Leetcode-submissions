class Solution {
public:
    int findans(vector<int>& dp, int i, vector<int>& days, vector<int>& costs) {
        if (i >= days.size()) {
            return 0; // Base case: no cost if all days are covered
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int ans = INT_MAX;
        ans = min(ans, costs[0] + findans(dp, i + 1, days, costs));
        int k = i;
        while (k < days.size() && days[k] - days[i] < 7) {
            k++;
        }
        ans = min(ans, costs[1] + findans(dp, k, days, costs));
        k = i;
        while (k < days.size() && days[k] - days[i] < 30) {
            k++;
        }
        ans = min(ans, costs[2] + findans(dp, k, days, costs));
        return dp[i] = ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), -1); // Correct size
        return findans(dp, 0, days, costs);
    }
};
