class Solution {
public:
    int mod = 1e9+7;

    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        hFences.insert(hFences.begin(), 1);
        hFences.push_back(m);

        vFences.insert(vFences.begin(), 1);
        vFences.push_back(n);

        unordered_set<long long> vDiff;

       
        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                vDiff.insert((long long)vFences[j] - vFences[i]);
            }
        }

        long long maxi = -1;

     
        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                long long diff = (long long)hFences[j] - hFences[i];
                if (vDiff.find(diff) != vDiff.end()) {
                    maxi = max(maxi, diff * diff);
                }
            }
        }

        if (maxi == -1) return -1;
        return maxi % mod;
    }
};
