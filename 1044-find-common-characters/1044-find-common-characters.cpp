class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> ans(26, INT_MAX);  // Corrected data type
        
        for(int i = 97; i <= 122; i++) {
            for(int j = 0; j < words.size(); j++) {
                int freq = count(words[j].begin(), words[j].end(), char(i));
                ans[i - 97] = min(freq, ans[i - 97]);
            }
        }
        
        vector<string> r;
        for(int i = 0; i < ans.size(); i++) {
            while(ans[i]-- > 0) {  // Prevent negative values from causing infinite loops
                r.push_back(string(1, char(i + 97)));  // Corrected character conversion
            }
        }
        return r;
    }
};
