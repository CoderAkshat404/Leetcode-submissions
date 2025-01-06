class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long long int i = 0; i * i <= c; i++) {
            long long x = i * i; // Use long long to prevent overflow
            long long int lo = 0, hi = sqrt(c - x); // Restrict hi to sqrt(c - x)
            while (lo <= hi) {
                long long m = lo + (hi - lo) / 2;
                long long sum = m * m + x;
                if (sum == c) {
                    return true;
                } else if (sum < c) {
                    lo = m + 1;
                } else {
                    hi = m - 1;
                }
            }
        }
        return false;
    }
};
