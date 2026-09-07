class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;

        map<char,int> lastindx;
        int n = s.length();

        vector<long long> pref(n, 0);
        pref[0] = 1;
        lastindx[s[0]] = 0;

        for(int i = 1; i < n; i++) {
            long long total = pref[i-1] % MOD;

            if(lastindx.find(s[i]) != lastindx.end()) {
                int previndx = lastindx[s[i]];

                if(previndx > 0) {
                    total = (total - pref[previndx-1] + MOD) % MOD;
                }
            }
            else {
                total = (total + 1) % MOD;
            }

            pref[i] = (pref[i-1] + total) % MOD;

            lastindx[s[i]] = i;
        }

        return pref[n-1];
    }
};