class Solution {
public:
    int countSubstringOccurrences(const string& str, const string& sub) {
        if (sub.empty()) return 0; // Edge case: empty substring
        
        int count = 0;
        size_t pos = 0;

        // Allow overlapping occurrences
        while ((pos = str.find(sub, pos)) != string::npos) {
            count++;
            pos++; // Move one position ahead to allow overlaps
        }

        return count;
    }

    int maximumLength(string s) {
        vector<string> v;
        
        // Generate all substrings
        for (int i = 0; i < s.length(); i++) {
            string p = "";
            for (int j = i; j < s.length(); j++) { // Include last character correctly
                p += s[j];
                v.push_back(p);
            }
        }

        vector<string> sp;
        
        // Filter special substrings (uniform substrings)
        for (int i = 0; i < v.size(); i++) {
            bool flag = true;
            for (int j = 0; j < v[i].length() - 1; j++) {
                if (v[i][j] != v[i][j + 1]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                sp.push_back(v[i]);
            }
        }

        int maxi = -1;

        // Find the maximum length of valid substrings
        for (int i = 0; i < sp.size(); i++) {
            int x = countSubstringOccurrences(s, sp[i]);
            if (x >= 3) { // Only consider substrings occurring at least 3 times
                maxi = max(maxi, (int)sp[i].length());
            }
        }

        return maxi == -1 ? -1 : maxi; // Return -1 if no valid substring is found
    }
};
