class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& v, int i) {
        if (target == 0) {
            ans.push_back(v);
            return;
        }
        if (i >= candidates.size() || target < 0) {
            return;
        }

        // Include current element and recurse
        v.push_back(candidates[i]);
        solve(candidates, target - candidates[i], ans, v, i + 1);
        v.pop_back();

        // Skip duplicates and move to the next element
        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
            i++;
        }
        solve(candidates, target, ans, v, i + 1);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(candidates.begin(), candidates.end());  // Sort to handle duplicates
        solve(candidates, target, ans, v, 0);
        return ans;
    }
};
