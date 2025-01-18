class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m; // To store the frequency of prefix sums
        int ans = 0, prefixSum = 0;
        
        m[0] = 1; // Initialize with a dummy prefix sum for subarrays starting at index 0
        
        for (int num : nums) {
            prefixSum += num;
            
            // Check if (prefixSum - k) exists in the map
            if (m.find(prefixSum - k) != m.end()) {
                ans += m[prefixSum - k];
            }
            
            // Increment the count of the current prefix sum
            m[prefixSum]++;
        }
        
        return ans;
    }
};
