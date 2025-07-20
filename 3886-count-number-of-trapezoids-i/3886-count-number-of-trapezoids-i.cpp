const int mod = 1e9 + 7;
const int inv2 = 500000004;

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        #define int long long
        map<int, vector<int>> adj;

        for (auto& p : points) {
            adj[p[1]].push_back(p[0]);
        }

        vector<vector<int>> newadj;
        for (auto& [y, xs] : adj) {
            if (xs.size() > 1)
                newadj.push_back(xs);
        }

        if (newadj.size() < 2) return 0;

        int ans = 0;
        vector<int> v;
        for (int i = 0; i < newadj.size(); i++) {
            int s1 = newadj[i].size();
            int x = ((s1 * (s1 - 1)) % mod * inv2) % mod;
            v.push_back(x);
        }

        int sum = v[0];
        for (int i = 1; i < v.size(); i++) {
            ans = (ans + (sum * v[i]) % mod) % mod;
            sum = (sum + v[i]) % mod;
        }

        return ans;
        #undef int
    }
};