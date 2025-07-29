class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> suff(n);
        int currOR = 0;
        for (int i = n - 1; i >= 0; i--) {
            currOR |= nums[i];
            suff[i] = currOR;
        }

        vector<vector<int>> pre(n, vector<int>(32, 0));
        for (int i = 0; i < 32; i++) {
            if ((nums[0] >> i) & 1) {
                pre[0][i] = 1;
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 32; j++) {
                if ((nums[i] >> j) & 1) {
                    pre[i][j] = pre[i - 1][j] + 1;
                } else {
                    pre[i][j] = pre[i - 1][j];
                }
            }
        }

        vector<int> ans;
        int l = 0, r = -1;
        currOR = 0;

        while (l < n) {
            while (r + 1 < n && ((currOR | nums[r + 1]) < suff[l])) {
                r++;
                currOR |= nums[r];
                if (currOR == suff[l]) {
                    break;
                }
            }

            ans.push_back(r - l + 2);

            if (r < l) {
                l++;
                r = l - 1;
                currOR = 0;
            } else {
                currOR = 0;
                for (int i = 0; i < 32; i++) {
                    int bit_count = pre[r][i] - pre[l][i];
                    if (bit_count > 0) {
                        currOR |= (1 << i);
                    }
                }
                l++;
            }
        }

        return ans;
    }
};
