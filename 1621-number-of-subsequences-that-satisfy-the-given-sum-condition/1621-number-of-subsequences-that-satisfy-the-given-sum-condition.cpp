int MOD = 1e9 + 7;

class Solution {
public:
    long long power(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }

    int numSubseq(vector<int>& nums, int target) {
        int ans = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int ele = nums[i];
            int x = upper_bound(nums.begin(), nums.end(), target - ele) - nums.begin();
            if (x <= i) {
                continue;
            }
            int totals = (x - i);
            ans = (ans + power(2, totals - 1)) % MOD;
        }
        return ans;
    }
};
