#include <numeric>
class Solution {
public:
    bool check(long long m, vector<int> d, vector<int>& r) {
        long long s1 = m - m / r[0];
        long long s2 = m - m / r[1];
        long long l = std::lcm(1LL * r[0], 1LL * r[1]);
        long long tot = m - m / l;
        return s1 >= d[0] && s2 >= d[1] && tot >= (long long)d[0] + d[1];
    }

    long long minimumTime(vector<int>& d, vector<int>& r) {
        if (d[0] > d[1]) { swap(d[0], d[1]); swap(r[0], r[1]); }
        long long ans = -1, lo = 1, hi = 1e12;
        while (lo <= hi) {
            long long m = lo + (hi - lo) / 2;
            if (check(m, d, r)) { ans = m; hi = m - 1; }
            else lo = m + 1;
        }
        return ans;
    }
};
