#include <vector>
#include <algorithm>
#include <numeric> // for gcd and lcm
#include <climits> // for LLONG_MIN
using namespace std;

class Solution {
public:
    int maxLength(vector<int>& v) {
        long long maxi = 0;

        for (size_t i = 0; i < v.size(); ++i) {
            long long p = 1;
            long long l = v[i];
            long long g = v[i];
            
            for (size_t j = i; j < v.size(); ++j) {
                // Check for potential overflow before multiplication
                if (p > LLONG_MAX / v[j]) {
                    break; // Stop further calculations for this subarray
                }

                p *= v[j];
                l = lcm(l, (long long)v[j]);
                g = gcd(g, v[j]);

                if (p == l * g) {
                    maxi = max(maxi, (long long)(j - i + 1));
                }
            }
        }
        
        return (int)maxi;
    }
};
