class Solution {
public:
    void dfs(int node, vector<int>& col, vector<vector<int>>& graph, int pc) {
        vector<int> v = graph[node];
        for (auto i : v) {
            if (col[i] == -1) {
                col[i] = 1 - pc;
                dfs(i, col, graph, col[i]);
            }
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> col(n, -1);
        
        // Loop through all nodes
        for (int i = 0; i < n; i++) {
            if (col[i] == -1) {
                col[i] = 1;  // Assign a color to the starting node
                dfs(i, col, graph, col[i]);  // Start DFS from node 'i' (not always 0)
            }
        }

        // Check if graph is bipartite
        bool flag = true;
        for (int i = 0; i < n; i++) {
            vector<int> v = graph[i];
            int pc = col[i];
            for (int j = 0; j < v.size(); j++) {
                if (pc == col[v[j]]) {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                break;
            }
        }
        return flag;
    }
};
