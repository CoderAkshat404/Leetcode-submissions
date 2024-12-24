#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    bool check(int m, vector<int>& piles, int h) {
        int hours = 0;
        for (int i = 0; i < piles.size(); i++) {
            // Use integer arithmetic to avoid precision issues
            hours += (piles[i] + m - 1) / m;
            if (hours > h) return false; // Early exit if we exceed allowed hours
        }
        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = 0;
        for (int i = 0; i < piles.size(); i++) {
            maxi = max(maxi, piles[i]);
        }
        
        int lo = 1;
        int hi = maxi;
        int ans = -1;

        while (lo <= hi) {
            int m = lo + (hi - lo) / 2;
            if (check(m, piles, h)) {
                ans = m;
                hi = m - 1; // Try for a smaller speed
            } else {
                lo = m + 1; // Try for a larger speed
            }
        }
        return ans;
    }
};
