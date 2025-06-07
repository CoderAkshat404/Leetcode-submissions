class Solution {
public:
    struct CompareChar {
        bool operator()(const pair<char, int>& a, const pair<char, int>& b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first > b.first;
        }
    };

    string clearStars(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, CompareChar> pq;
        vector<int> ind;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '*') {
                int x = pq.top().second;
                ind.push_back(x);
                pq.pop();
            }
            else {
                pq.push({s[i], i});
            }
        }


        string ans;
        if (ind.size() > 0) {
            sort(ind.begin(), ind.end());
            int i = 0;
            for (int j = 0; j < s.length(); j++) {
        
                if (s[j] == '*') {
                    continue;
                }
                if (i >= ind.size()) {
                    ans.push_back(s[j]);
                }
                else if (j == ind[i]) {
                    i++;
                    continue;
                }
                else {
                    ans.push_back(s[j]);
                }
            }
            return ans;
        }
        else {
            return s;
        }
    }
};
