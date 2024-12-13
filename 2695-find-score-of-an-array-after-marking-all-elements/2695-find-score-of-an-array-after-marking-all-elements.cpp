class Solution {
public:
    long long findScore(vector<int>& nums) {
        vector<pair<int, int>> v;
        for (int i = 0; i < nums.size(); i++) {
            pair<int, int> p = {nums[i], i};
            v.push_back(p);
        }
        sort(v.begin(), v.end());
        unordered_map<int, bool> m;
        long long sum = 0;

        for (auto& i : v) {
            if (!m[i.second]) {
                sum += i.first;
                m[i.second] = true;  // Mark current index as processed
                if (i.second - 1 >= 0) m[i.second - 1] = true;  // Mark left neighbor
                if (i.second + 1 < nums.size()) m[i.second + 1] = true;  // Mark right neighbor
            }
        }
        return sum;
    }
};
