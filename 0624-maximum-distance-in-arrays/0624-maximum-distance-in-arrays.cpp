class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        vector<int> mini;
        vector<int> maxi;
        unordered_map<int, int> mMin, mMax;
        
        for (int i = 0; i < arrays.size(); i++) {
            mini.push_back(arrays[i][0]);
            maxi.push_back(arrays[i].back());
            mMin[arrays[i][0]] = i;
            mMax[arrays[i].back()] = i;
        }
        
        sort(mini.begin(), mini.end());
        sort(maxi.begin(), maxi.end());
        
        int maxDist = INT_MIN;
        
        // Case 1: The max and min come from different arrays
        if (mMin[mini[0]] != mMax[maxi.back()]) {
            maxDist = abs(maxi.back() - mini[0]);
        }
        // Case 2: The max and min come from the same array, so consider second largest/smallest
        else {
            maxDist = max(abs(maxi.back() - mini[1]), abs(maxi[maxi.size() - 2] - mini[0]));
        }
        
        return maxDist;
    }
};
