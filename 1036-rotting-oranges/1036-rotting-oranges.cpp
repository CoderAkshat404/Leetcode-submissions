class Solution {
public:
    int maxi;
    int n, m;
    vector<int> dx;
    vector<int> dy;

    bool check(int i, int j, vector<vector<int>>& grid) {
        if (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1) {
            return true;
        }
        return false;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        maxi = 0;
        n = grid.size();
        m = grid[0].size();
        dx = {1, 0, -1, 0};
        dy = {0, 1, 0, -1};

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;

        // Push all rotten oranges into the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        // BFS from all rotten oranges
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int i = it.first.first;
            int j = it.first.second;
            int time = it.second;
            maxi = max(maxi, time);

            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (check(ni, nj, grid) && vis[ni][nj] == 0) {
                    vis[ni][nj] = 1;
                    q.push({{ni, nj}, time + 1});
                }
            }
        }

        // Check if any fresh orange is left
        bool flag = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                break;
            }
        }

        if (flag) {
            return maxi;
        }
        return -1;
    }
};
