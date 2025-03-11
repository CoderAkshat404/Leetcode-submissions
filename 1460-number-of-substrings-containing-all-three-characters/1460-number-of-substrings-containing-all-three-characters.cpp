class Solution {
public:
    bool isvalid(unordered_map<char, int>& m) {
        return m['a'] > 0 && m['b'] > 0 && m['c'] > 0;
    }

    int numberOfSubstrings(string s) {
        int n = s.length();
        int l = 0, r = 0;
        unordered_map<char, int> m;
        int ans = 0;

        while (r < n) {
            m[s[r]]++;

            while (isvalid(m)) { 
                ans += n - r;
                m[s[l]]--;
                // if (m[s[l]] == 0) {
                //     m.erase(s[l]);  // Remove character when count becomes zero
                // }
                l++;
            }
            r++;
        }
        return ans;
    }
};
