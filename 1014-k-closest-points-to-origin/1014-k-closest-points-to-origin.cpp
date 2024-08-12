class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        unordered_map<double, vector<pair<int, int>>> m;
        vector<double> v;
        
        for(int i = 0; i < points.size(); i++) {
            double a1 = points[i][0];
            double a2 = points[i][1];
            double x1 = a1 * a1;
            double y1 = a2 * a2;
            double dist = sqrt(x1 + y1);
            pair<int, int> p = {points[i][0], points[i][1]};
            
            // Map now stores a vector of pairs to handle multiple points with the same distance
            m[dist].push_back(p);
            v.push_back(dist);
        }
        
        // Sort the vector of distances
        sort(v.begin(), v.end());
        vector<vector<int>> ans;
        
        // Retrieve the k closest points
        for(int i = 0; i < k; i++) {
            double dist = v[i];
            for (const auto& p : m[dist]) {
                if (ans.size() < k) {
                    ans.push_back({p.first, p.second});
                } else {
                    break;
                }
            }
        }
        
        return ans;
    }
};
