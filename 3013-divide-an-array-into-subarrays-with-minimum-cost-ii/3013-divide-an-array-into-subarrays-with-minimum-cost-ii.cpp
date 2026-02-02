class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        if (k == 1) return nums[0];

        long long ans = nums[0];

        multiset<int> ms, ms2;
        long long sum = 0;
        long long mini = LLONG_MAX;

        // initial window
        for (int i = 1; i <= 1 + dist && i < n; i++) {
            sum += nums[i];
            ms.insert(nums[i]);
            if ((int)ms.size() > k - 1) {
                auto it = prev(ms.end());
                sum -= *it;
                ms2.insert(*it);
                ms.erase(it);
            }
        }

        mini = sum;

        int i = 1;
        int j = 1 + dist;

        while (j + 1 < n) {
            // add new element
            if (!ms.empty() && nums[j + 1] < *prev(ms.end())) {
                ms.insert(nums[j + 1]);
                sum += nums[j + 1];
                auto it = prev(ms.end());
                sum -= *it;
                ms2.insert(*it);
                ms.erase(it);
            } else {
                ms2.insert(nums[j + 1]);
            }

            // remove outgoing element
            if (ms.find(nums[i]) != ms.end()) {
                sum -= nums[i];
                ms.erase(ms.find(nums[i]));
                if (!ms2.empty()) {
                    auto it = ms2.begin();
                    sum += *it;
                    ms.insert(*it);
                    ms2.erase(it);
                }
            } else {
                ms2.erase(ms2.find(nums[i]));
            }

            mini = min(mini, sum);
            i++;
            j++;
        }

        return ans + mini;
    }
};
