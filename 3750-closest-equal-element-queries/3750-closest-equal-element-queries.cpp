class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> m;
        int n = nums.size();

        // Store the indices for each number
        for (int i = 0; i < n; i++) {
            m[nums[i]].push_back(i);
        }

        vector<int> ans;
        for (int y : queries) {
            int x = nums[y];
            vector<int>& v = m[x]; 
            if(v.size()==1){
                ans.push_back(-1);
                continue;
            }

            int idx = lower_bound(v.begin(), v.end(), y) - v.begin();
            int dist = INT_MAX;

            if (idx > 0) dist = min(dist, y - v[idx - 1]); 
            if (idx < v.size() - 1) dist = min(dist, v[idx + 1] - y); 
           
            if (y == v.back() || y == v[0]) {
                dist = min(dist, (n - v.back()) + v[0]);
            }

            if (dist == INT_MAX) dist = -1;
            ans.push_back(dist);
        }
        
        return ans;
    }
};
