class Solution {
public:
    int characterReplacement(string s, int k) {
         int n = s.size();
        // m[c] = count of character 'A'+c in the current window
        vector<int> m(26, 0);
        int l = 0, r = -1;
        int ans = 0;
        int maxf = 0; // highest frequency of any single character in [l..r]

        while (r < n) {
            // 1) Try to expand the right end as far as we can without exceeding k replacements
            while (r + 1 < n) {
                int nextR = r + 1;
                int idx = s[nextR] - 'A';
                // If we include s[nextR], the new max frequency would be:
                int wouldBeMaxf = max(maxf, m[idx] + 1);
                // Window size after including nextR:
                int windowSize = nextR - l + 1;
                // Number of changes required = windowSize - wouldBeMaxf
                int needed = windowSize - wouldBeMaxf;
                if (needed <= k) {
                    // Grow the window
                    r = nextR;
                    m[idx]++;
                    maxf = wouldBeMaxf;
                } else {
                    break;
                }
            }

            // 2) Update answer: all substrings [l..i] for i in [l..r] are valid, so
            //    we can take the full window length
            ans = max(ans, r - l + 1);

            // 3) Shrink from the left
            if (r < l) {
                // Window is empty, move both pointers forward
                l++;
                r = l - 1;
            } else {
                // Remove s[l] from the window and advance l
                int idx = s[l] - 'A';
                m[idx]--;
                l++;
                // Note: we do NOT decrease maxf here. This is the standard trick
                // that allows O(n) time—maxf may “lag” but never leads to a wrong answer.
            }
        }

        return ans;
        
    }
};