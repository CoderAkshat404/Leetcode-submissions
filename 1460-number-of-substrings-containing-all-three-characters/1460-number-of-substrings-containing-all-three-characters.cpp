class Solution {
public:
    bool isvalid(unordered_map<char, int>& m) {
        return (m.size() == 3);
    }

    int numberOfSubstrings(string s) {
        int n = s.length();
        int l = 0, r = 0;
        unordered_map<char, int> m;
        int ans = 0;
        
        while (r < n) {
            m[s[r]]++;

            while (m.size() == 3) {  // We have at least one 'a', 'b', and 'c'
                ans += n - r;
                m[s[l]]--;
                if (m[s[l]] == 0) {
                    m.erase(s[l]); // Remove character from map when count reaches 0
                }
                l++;
            }
            r++;
        }
        return ans;
    }
};
