#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> rank, parent, size;
    
    DSU(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);  // Correctly initialize size to 1
        
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int n) {
        if (n == parent[n]) return n;
        return parent[n] = findParent(parent[n]);
    }

    void unionByRank(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv) return;

        if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else {
            parent[pu] = pv;
            rank[pv]++;
        }
    }

    void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv) return;

        if (size[pu] > size[pv]) {
            parent[pv] = pu;
            size[pu] += size[pv];  // Correct size update
        } else {
            parent[pu] = pv;
            size[pv] += size[pu];  // Correct size update
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        DSU ds(n * m);
        
        // Step 1: Union all existing 1s in the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    int u = i * m + j;
                    
                    if (i - 1 >= 0 && grid[i - 1][j] == 1) {
                        int v = (i - 1) * m + j;
                        ds.unionBySize(u, v);
                    }
                    if (j - 1 >= 0 && grid[i][j - 1] == 1) {
                        int v = i * m + (j - 1);
                        ds.unionBySize(u, v);
                    }
                    if (i + 1 < n && grid[i + 1][j] == 1) {
                        int v = (i + 1) * m + j;
                        ds.unionBySize(u, v);
                    }
                    if (j + 1 < m && grid[i][j + 1] == 1) {
                        int v = i * m + (j + 1);
                        ds.unionBySize(u, v);
                    }
                }
            }
        }

        // Step 2: Check for largest island size
        int maxi = 0;

        // Edge case: If the grid is already all 1s
        bool allOnes = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    allOnes = false;
                    break;
                }
            }
            if (!allOnes) break;
        }
        if (allOnes) return n * m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> s;

                    if (i - 1 >= 0 && grid[i - 1][j] == 1) {
                        s.insert(ds.findParent((i - 1) * m + j));
                    }
                    if (j - 1 >= 0 && grid[i][j - 1] == 1) {
                        s.insert(ds.findParent(i * m + (j - 1)));
                    }
                    if (i + 1 < n && grid[i + 1][j] == 1) {
                        s.insert(ds.findParent((i + 1) * m + j));
                    }
                    if (j + 1 < m && grid[i][j + 1] == 1) {
                        s.insert(ds.findParent(i * m + (j + 1)));
                    }

                    int newSize = 1;  // Flip 0 to 1
                    for (auto parent : s) {
                        newSize += ds.size[parent];  // Add sizes of neighboring components
                    }
                    maxi = max(maxi, newSize);
                }
            }
        }

        return maxi;
    }
};
