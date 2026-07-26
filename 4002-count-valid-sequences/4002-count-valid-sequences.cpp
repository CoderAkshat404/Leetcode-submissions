class Solution {
public:
    int mod = 1e9 + 7;

    int binpow(int a, int b) {
        if (b == 0) return 1;

        if (b & 1)
            return (1LL * a * binpow(a, b - 1)) % mod;

        int x = binpow(a, b / 2);
        return (1LL * x * x) % mod;
    }

    int inverse(int x) {
        return binpow(x, mod - 2);
    }

    int fact[1000005];

    void precompute(int upto) {
        fact[0] = 1;
        for (int i = 1; i <= upto; i++) {
            fact[i] = (1LL * fact[i - 1] * i) % mod;
        }
    }

    int ncr_fact(int n, int r) {
        if (r < 0 || r > n) return 0;

        int num = fact[n];
        int den = (1LL * fact[n - r] * fact[r]) % mod;

        return (1LL * num * inverse(den)) % mod;
    }

    int countValidSequences(int n, int k) {
        precompute(n - 1);

        int total = ncr_fact(n - 1, k - 1);

        int odd = 0;
        if ((n - k) % 2 == 0) {
            odd = ncr_fact((n + k - 2) / 2, k - 1);
        }

        return (total - odd + mod) % mod;
    }
};