class Solution {
public:
    int countOfSubstrings(string word, int k) {
        int count = 0;
        for (int i = 0; i < word.length(); i++) {
            unordered_map<char, bool> m;
            m['a'] = false;
            m['e'] = false;
            m['i'] = false;
            m['o'] = false;
            m['u'] = false;
            int x = 0;
            for (int j = i; j < word.length(); j++) {
                bool flag = true;
                if (word[j] == 'a' || word[j] == 'e' || word[j] == 'o' || word[j] == 'i' || word[j] == 'u') {
                    m[word[j]] = true;
                } else {
                    x++;
                }
                
                for (auto i : m) {
                    if (i.second == false) {
                        flag = false;
                    }
                }
                
                if (flag && x == k) {
                    count++;
                    // Removed break to continue checking all substrings
                }
            }
        }
        return count;
    }
};
