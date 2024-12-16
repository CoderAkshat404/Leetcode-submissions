class Solution {
public:
    int findans(int i, vector<int>& nums, vector<int>& dp) {
        if (i >= nums.size()) {
            return 0; // Base case: No LIS starts beyond the last index
        }
        if (dp[i] != -1) {
            return dp[i]; // Use precomputed result
        }
        
        int maxLength = 1; // The LIS starting from nums[i] is at least 1 (nums[i] itself)
        for (int k = i + 1; k < nums.size(); k++) {
            if (nums[k] > nums[i]) {
                maxLength = max(maxLength, 1 + findans(k, nums, dp)); // Recur for index k
            }
        }
        dp[i] = maxLength; // Store result in dp
        return dp[i];
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1); // Initialize dp array with -1
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, findans(i, nums, dp)); // Compute LIS starting from each index
        }
        return ans;
    }
};
