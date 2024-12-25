class Solution {
public:
    int check(int m, vector<int>& nums, int threshold) {
        int x = 0;
        for (int i = 0; i < nums.size(); i++) {
            x += ceil((double)nums[i] / m);
        }
        return x <= threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1; // Start from 1 to avoid division by zero
        int hi = 1e7;
        int ans = -1;
        
        while (lo <= hi) {
            int m = lo + (hi - lo) / 2; // Correct midpoint calculation
            if (check(m, nums, threshold)) {
                ans = m;
                hi = m - 1;
            } else {
                lo = m + 1;
            }
        }
        return ans;
    }
};
