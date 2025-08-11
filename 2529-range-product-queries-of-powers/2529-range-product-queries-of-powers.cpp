class Solution {
public:
    int mod = 1e9 + 7;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }

    long long modInverse(long long a) {
        return modPow(a, mod - 2); 
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long long> powers;
        for (int i = 0; i < 32; i++) {
            if ((n >> i) & 1) {
                powers.push_back((1LL << i) % mod);
            }
        }

        vector<long long> pre(powers.size());
        pre[0] = powers[0] % mod;
        for (int i = 1; i < (int)pre.size(); i++) {
            pre[i] = (pre[i - 1] * powers[i]) % mod;
        }

        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            long long x = pre[r];
            if (l > 0) {
                x = (x * modInverse(pre[l - 1])) % mod;
            }
            ans.push_back((int)x);
        }
        return ans;
    }
};
