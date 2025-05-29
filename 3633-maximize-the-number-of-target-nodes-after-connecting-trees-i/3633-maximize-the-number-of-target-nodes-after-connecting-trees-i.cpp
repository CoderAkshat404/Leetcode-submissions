class Solution {
public:
    void dfs(int node, vector<int>& v1, vector<int>& vis1, vector<vector<int>>& adj1, int k, int dist, int psv) {
        if (dist > k) return;
        vis1[node] = 1;
        v1[psv]++;
        for (int i : adj1[node]) {
            if (!vis1[i]) {
                dfs(i, v1, vis1, adj1, k, dist + 1, psv);
            }
        }
    }

    void dfs2(int node, vector<int>& v2, vector<int>& vis2, vector<vector<int>>& adj2, int k, int dist, int psv) {
        if (dist > k) return;
        vis2[node] = 1;
        v2[psv]++;
        for (int i : adj2[node]) {
            if (!vis2[i]) {
                dfs2(i, v2, vis2, adj2, k, dist + 1, psv);
            }
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n1 = edges1.size() + 1;
        int n2 = edges2.size() + 1;

        vector<vector<int>> adj1(n1);
        vector<vector<int>> adj2(n2);

        for (auto& edge : edges1) {
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }

        for (auto& edge : edges2) {
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }

        vector<int> v1(n1, 0), v2(n2, 0);
        vector<int> vis1(n1, 0), vis2(n2, 0);

        for (int i = 0; i < n1; i++) {
            fill(vis1.begin(), vis1.end(), 0);
            dfs(i, v1, vis1, adj1, k, 0, i);
        }

        for (int i = 0; i < n2; i++) {
            fill(vis2.begin(), vis2.end(), 0);
            dfs2(i, v2, vis2, adj2, k - 1, 0, i);
        }

        int maxi = *max_element(v2.begin(), v2.end());

        for (int i = 0; i < n1; i++) {
            v1[i] += maxi;
        }

        return v1;
    }
};
