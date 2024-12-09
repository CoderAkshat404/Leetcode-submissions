class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> ans;
        vector<int> dikkat; // Indices where consecutive elements have the same parity

        // Step 1: Identify indices with parity issues
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] % 2 == nums[i + 1] % 2) {
                dikkat.push_back(i + 1); // Store the index of the second element in the pair
            }
        }

        // Step 2: Process each query
        for (const auto& query : queries) {
            int s = query[0];
            int e = query[1];
            bool flag = true; // Assume the subarray is special

            // Step 3: Check if there is any index in 'dikkat' within the range [s + 1, e]
            for (int idx : dikkat) {
                if (idx > s && idx <= e) {
                    flag = false; // Found a parity issue in the range
                    break;
                }
            }

            ans.push_back(flag); // Append the result for this query
        }

        return ans;
    }
};
