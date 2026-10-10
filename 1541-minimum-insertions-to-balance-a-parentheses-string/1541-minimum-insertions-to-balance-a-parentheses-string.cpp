
class Solution {
public:
    int minInsertions(string s) {
        vector<char> v;
        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                v.push_back('(');
            } else {
                if ((i + 1 < s.length() && s[i + 1] != ')') || i + 1 == s.length()) {
                    ans++;
                }

                if (v.empty()) {
                    ans++;
                    v.push_back('(');
                }
                    v.pop_back();
                

                if (i + 1 < s.length() && s[i + 1] == ')') {
                    i++;
                }
            }
        }

        ans += v.size() * 2;
        return ans;
    }
};
