static vector<int> v;
void computeSieve() {
    v.assign(50001, true);
    v[0] = v[1] = false;
    for (int i = 2; i * i <= 50000; ++i) {
        if (v[i]) {
            for (int j = i * i; j <= 50000; j += i)
                v[j] = false;
        }
    }
}

class Solution {
public:
    bool check(multiset<int>& m, vector<int>& nums, int r, int k) {
        return ((m.size() < 1) || (m.size() >= 1 && ((v[nums[r + 1]] == 0) ||
                (v[nums[r + 1]] == 1 && *m.rbegin() - nums[r + 1] <= k &&
                 nums[r + 1] - *m.begin() <= k && nums[r + 1] - *m.rbegin() <= k))));
    }

    int primeSubarray(vector<int>& nums, int k) {
        computeSieve();
        multiset<int> ms;
        deque<int> q;  // holds indices of primes in window
        int l = 0, rmin = -1, rmax = -1;
        int n = nums.size();
        long long ans = 0;

        while (l < n) {
            while (rmax + 1 < n && check(ms, nums, rmax, k)) {
                rmax++;
                if (v[nums[rmax]]) {
                    ms.insert(nums[rmax]);
                    q.push_back(rmax);
                    if (ms.size() == 2) {
                        rmin = rmax; // initial rmin
                    }
                }
            }

            if (ms.size() >= 2 && rmin != -1) {
                // Update rmin to second prime in range
                if (q.size() >= 2) rmin = q[1];
                ans += (rmax - rmin + 1);
            }

            if (rmax < l) {
                l++;
                rmax = l - 1;
            } else {
                if (v[nums[l]]) {
                    ms.erase(ms.find(nums[l]));
                    if (!q.empty() && q.front() == l) {
                        q.pop_front();
                    }

                    if (ms.size() < 2) {
                        rmin = -1;
                    } else {
                        if (q.size() >= 2) rmin = q[1];
                        else rmin = -1;
                    }
                }
                l++;
            }
        }

        return ans;
    }
};
