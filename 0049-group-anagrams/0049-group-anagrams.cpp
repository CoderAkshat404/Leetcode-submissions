class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, bool> m;
        vector<vector<string>> ans;
        
        for (int i = 0; i < strs.size(); i++) {
            if (m[strs[i]] == true) {
                continue; // Skip already processed strings
            }
            vector<string> v;
            
            for (int j = 0; j < strs.size(); j++) {
                bool flag = true; // Reset flag for each string comparison
                
                // Ensure both strings have the same length before comparing characters
                if (strs[j].length() != strs[i].length()) {
                    flag = false;
                } else {
                    // Check if character counts match for both strings
                    for (int p = 0; p < strs[j].length(); p++) {
                        if (count(strs[j].begin(), strs[j].end(), strs[j][p]) !=
                            count(strs[i].begin(), strs[i].end(), strs[j][p])) {
                            flag = false; // Mark as non-anagram if any mismatch found
                            break; // Exit the loop since no need to check further
                        }
                    }
                }
                
                if (flag) {
                    v.push_back(strs[j]); // Add anagram to the current group
                    m[strs[j]] = true; // Mark as processed
                }
            }
            ans.push_back(v); // Add the anagram group to the result
        }
        
        return ans;
    }
};
