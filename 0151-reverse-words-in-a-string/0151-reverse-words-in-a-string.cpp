class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        int i = 0;
        string p = "";

        while (i < s.length()) {
            while (i < s.length() && s[i] == ' ') {
                i++;
            }
            while (i < s.length() && s[i] != ' ') {
                p += s[i];
                i++;
            }
            if (!p.empty()) {
                v.push_back(p);
                p = "";
            }
        }

        reverse(v.begin(), v.end());
        s = "";
        for (int j = 0; j < v.size(); j++) {
            s += v[j];
            if (j != v.size() - 1) {
                s += " ";
            }
        }

        return s;
    }
};
