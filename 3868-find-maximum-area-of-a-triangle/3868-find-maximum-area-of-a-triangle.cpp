class Solution {
public:
    long long maxArea(vector<vector<int>>& coords) {
        long long ans = 0;
        int ymax = -1;
        int xmax = -1;
        int xmin = 1e9;
        int ymin = 1e9;
        sort(coords.begin(), coords.end());
        for (int i = 0; i < coords.size(); i++) {
            xmax = max(xmax, coords[i][0]);
            ymax = max(ymax, coords[i][1]);
            xmin = min(xmin, coords[i][0]);
            ymin = min(ymin, coords[i][1]);
        }
        vector<vector<int>> ysame(ymax + 1);
        for (int i = 0; i < coords.size(); i++) {
            ysame[coords[i][1]].push_back(coords[i][0]);
        }
        vector<vector<int>> xsame(xmax + 1);
        for (int i = 0; i < coords.size(); i++) {
            xsame[coords[i][0]].push_back(coords[i][1]);
        }
        for (int i = 0; i < xsame.size(); i++) {
            if (xsame[i].size() >= 2) {
                int lo = xsame[i][0];
                int hi = xsame[i].back();
                long long maxi = max(1LL * (hi - lo) * (i - xmin), 1LL * (hi - lo) * (xmax - i));
                ans = max(ans, maxi);
            }
        }
        for (int i = 0; i < ysame.size(); i++) {
            if (ysame[i].size() >= 2) {
                int lo = ysame[i][0];
                int hi = ysame[i].back();
                long long maxi = max(1LL * (hi - lo) * (i - ymin), 1LL * (hi - lo) * (ymax - i));
                ans = max(ans, maxi);
            }
        }
        if (ans == 0) {
            return -1;
        }
        return ans;
    }
};