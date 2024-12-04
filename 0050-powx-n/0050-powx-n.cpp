class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }

        long long absN = abs((long long)n); // Handle negative and prevent overflow for INT_MIN
        double result = 1.0;

        while (absN > 0) {
            if (absN % 2 == 1) { // If the current power is odd
                result *= x;
            }
            x *= x;         // Square the base
            absN /= 2;      // Halve the exponent
        }

        // If the original exponent was negative, return 1 / result
        return n < 0 ? 1.0 / result : result;
    }
};
