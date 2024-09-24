class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, bool> m;
        vector<vector<string>> ans;
        
        for (int i = 0; i < strs.size(); i++) {
            if (m[strs[i]] == true) {
                continue;
            }
            vector<string> v;
            
            for (int j = 0; j < strs.size(); j++) {
                bool flag = true;
                
                if (strs[j].length() != strs[i].length()) {
                    flag = false;
                } else {
                    for (int p = 0; p < strs[j].length(); p++) {
                        if (count(strs[j].begin(), strs[j].end(), strs[j][p]) !=
                            count(strs[i].begin(), strs[i].end(), strs[j][p])) {
                            flag = false;
                            break;
                        }
                    }
                }
                
                if (flag) {
                    v.push_back(strs[j]);
                    m[strs[j]] = true;
                }
            }
            ans.push_back(v);
        }
        
        return ans;
    }
};
