class Solution {
public:
    void solve(string &s, vector<int>& ans) {
        unordered_map<char, int> last_occurrence;
        for (int i = 0; i < s.size(); ++i) {
            last_occurrence[s[i]] = i;
        }
        int last = 0, start = 0;
        for (int i = 0; i < s.size(); ++i) {
            last = max(last, last_occurrence[s[i]]);
            if (i == last) {
                ans.push_back(last - start + 1);
                start = i + 1;
            }
        }  
    }

    vector<int> partitionLabels(string s) {
        vector<int> ans;
        solve(s, ans);
        return ans;
    }
};
