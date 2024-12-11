class Solution {
public:
    bool isValid(vector<int>& nums, int k, int len) {
        // Check if there exists a subsequence of length `len` that is valid
        for (int start = 0; start + len - 1 < nums.size(); start++) {
            if (nums[start + len - 1] - nums[start] <= 2 * k) {
                return true;
            }
        }
        return false;
    }

    int maximumBeauty(vector<int>& nums, int k) {
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Binary search on the maximum subsequence length
        int low = 1, high = nums.size(), ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Step 3: Validate if `mid` is a valid subsequence length
            if (isValid(nums, k, mid)) {
                ans = mid;      // Update answer
                low = mid + 1;  // Try for a larger length
            } else {
                high = mid - 1; // Try for a smaller length
            }
        }

        return ans;
    }
};
