class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for(int i = 0; i < words.size(); i++) {
            m[words[i]]++;
        }

        vector<pair<int, string>> v;
        for(auto i : m) {
            v.push_back({i.second, i.first});
        }

        // Custom comparator to sort by frequency in descending order and lexicographically if the frequency is the same
        auto cmp = [](pair<int, string>& a, pair<int, string>& b) {
            if(a.first == b.first) {
                return a.second < b.second;  // lexicographical order if frequencies are the same
            }
            return a.first > b.first;  // sort by frequency in descending order
        };

        // Sort the vector using the custom comparator
        sort(v.begin(), v.end(), cmp);

        vector<string> ans;
        // Collect the top K frequent words
        for(int i = 0; i < k; i++) {
            ans.push_back(v[i].second);
        }

        return ans;
    }
};
