class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int l = lower - nums[i];
            int r = upper - nums[i];
            auto it1 = lower_bound(nums.begin(), nums.begin() + i, l);
            auto it2 = upper_bound(nums.begin(), nums.begin() + i, r);
            ans += (it2 - it1);
        }
        return ans;
    }
};
