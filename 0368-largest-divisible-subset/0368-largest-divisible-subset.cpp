class Solution {
public:
    vector<vector<vector<int>>> dp;

    vector<int> solve(int i, vector<int>& nums, int prevIdx) {
        if (i == nums.size()) return {};

        if (!dp[i][prevIdx + 1].empty()) return dp[i][prevIdx + 1];

        // Option 1: Skip current element
        vector<int> exclude = solve(i + 1, nums, prevIdx);

        // Option 2: Include current element (if divisible)
        vector<int> include;
        if (prevIdx == -1 || nums[i] % nums[prevIdx] == 0) {
            include = solve(i + 1, nums, i);
            include.insert(include.begin(), nums[i]);
        }

        // Choose the better option
        dp[i][prevIdx + 1] = (include.size() > exclude.size()) ? include : exclude;
        return dp[i][prevIdx + 1];
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        dp.resize(n, vector<vector<int>>(n + 1));  // prevIdx + 1 ranges from 0 to n
        return solve(0, nums, -1);
    }
};
