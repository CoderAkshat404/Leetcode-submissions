class Solution {
public:
    int solve(string s){
        int l = 0, r = -1, n = s.length(), ans = 0;
        unordered_map<char, int> m;

        while (l < n) {
            while (r + 1 < n && (m['a'] == 0 || m['b'] == 0 || m['c'] == 0)) {
                r++;
                m[s[r]]++;
            }
            if (m['a'] > 0 && m['b'] > 0 && m['c'] > 0)
                ans += n - r;

            if (r < l) {
                l++;
                r = l - 1;
            } else {
                m[s[l]]--;
                l++;
            }
        }
        return ans;
    }

    int numberOfSubstrings(string s) {
        return solve(s);
    }
};
