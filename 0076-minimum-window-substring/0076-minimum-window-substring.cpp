class Solution {
public:
    bool allmatched(unordered_map<char, int> &m, unordered_map<char, int> &need) {
        for (auto i : need) {
            if (m[i.first] < i.second) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        unordered_map<char, int> need, m;
        for (char c : t) need[c]++;
        
        int r = -1, l = 0;
        int minLen = INT_MAX, start = 0;
        int n = s.length();

        while (l < n) {
            while (r + 1 < n && !allmatched(m, need)) {
                r++;
                m[s[r]]++;
            }

            if (allmatched(m, need) && r - l + 1 < minLen) {
                start = l;
                minLen = r - l + 1;
            }

            if (r < l) {
                l++;
                r = l - 1;
            } else {
                m[s[l]]--;
                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
