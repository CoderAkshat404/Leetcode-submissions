class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        vector<pair<int,int>> v;
        for(int i = 0; i < costs.size(); i++){
            v.push_back({costs[i], capacity[i]});
        }
        sort(v.begin(), v.end());
        
        vector<int> pref(v.size());
        pref[0] = v[0].second;
        for(int i = 1; i < v.size(); i++){
            pref[i] = max(v[i].second, pref[i-1]);
        }
        
        long long maxi = 0; 
        
        for(int i = 0; i < v.size(); i++){
            if (v[i].first < budget) {
                maxi = max(maxi, (long long)v[i].second);
            } else {
                break; 
            }

            int rem_budget = budget - v[i].first;
            
            auto it_iter = upper_bound(v.begin(), v.end(), make_pair(rem_budget, 0));
            int it = distance(v.begin(), it_iter) - 1;
            
            int valid_idx = min(it, i - 1);
            
            if (valid_idx >= 0) {
                maxi = max(maxi, (long long)v[i].second + pref[valid_idx]);
            }
        }
        return maxi;
    }
};