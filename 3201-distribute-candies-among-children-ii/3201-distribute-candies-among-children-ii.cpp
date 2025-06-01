class Solution {
public:
    long long binomialCoefficient(int n, int k) {
    if (k < 0 || k > n) return 0;
    if (k == 0 || k == n) return 1;
    long long res = 1;
    for (int i = 1; i <= k; ++i) {
        res *= (n - i + 1);
        res /= i;
    }
    return res;
}

// Main function to count the number of bounded compositions
long long countBoundedCompositions(int r, int n, int limit) {
    long long total = 0;
    for (int k = 0; k <= r; ++k) {
        int sign = (k % 2 == 0) ? 1 : -1;
        long long ways = binomialCoefficient(r, k) * binomialCoefficient(n - k * (limit + 1) + r - 1, r - 1);
        total += sign * ways;
    }
    return total;
}
    long long distributeCandies(int n, int limit) {
       return countBoundedCompositions(3,n,limit);
        
    }
};