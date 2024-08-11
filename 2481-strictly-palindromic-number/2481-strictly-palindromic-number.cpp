class Solution {
public:
    bool check(int n, int i) {
        string s = "";
        while (n != 0) {
            int x = n % i;
            n = n / i;
            string v = to_string(x);
            s += v;
        }
        int p = 0;
        int j = s.length() - 1;
        while (p <= j) {
            if (s[p] != s[j]) {
                return false;
            }
            p++; // Increment p
            j--; // Decrement j
        }
        return true;
    }

    bool isStrictlyPalindromic(int n) {
        for (int i = 2; i <= n - 2; i++) {
            bool ans = check(n, i);
            if (!ans) {
                return false;
            }
        }
        return true;
    }
};
