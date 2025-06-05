class Solution {
public:
    int dist;

    void insert(int x, unordered_map<int, int>& m) {
        m[x]++;
        if (m[x] == 1) dist++;
    }

    void rem(int x, unordered_map<int, int>& m) {
        m[x]--;
        if (m[x] == 0) dist--;
    }

    int solve(vector<int>& nums, int k) {
        int n = nums.size();
        dist = 0;
        unordered_map<int, int> m;
        int r = -1, l = 0, ans = 0;

        while (r < n) {
            while (r + 1 < n && (dist < k || (dist == k && m[nums[r + 1]] > 0))) {
                r++;
                insert(nums[r], m);
            }

            ans += r - l + 1;

            if (r < l) {
                l++;
                r = l - 1;
            } else {
                rem(nums[l], m);
                l++;
            }
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};
