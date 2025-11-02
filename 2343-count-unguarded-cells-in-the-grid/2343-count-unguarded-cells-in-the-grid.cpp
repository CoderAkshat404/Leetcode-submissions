class Solution {
public:
    bool check(int x, int y, int m, int n, set<pair<int,int>>& s) {
        return (x >= 0 && x < m && y >= 0 && y < n && s.find({x, y}) == s.end());
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<vector<int>>> vis(m, vector<vector<int>>(n, vector<int>(4, 0))); // 3D vis
        vector<vector<int>> cellVisited(m, vector<int>(n, 0)); // To mark overall visited cells later
        queue<array<int,3>> q; // {x, y, dir}
        set<pair<int,int>> s;

        for (auto &w : walls)
            s.insert({w[0], w[1]});

        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};

        for (auto &g : guards)
            q.push({g[0], g[1], -1});

        while (!q.empty()) {
            auto [x, y, dir] = q.front();
            q.pop();

            cellVisited[x][y] = 1;

            if (dir == -1) {
                // Spread in all directions from guard
                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (check(nx, ny, m, n, s) && !vis[nx][ny][k]) {
                        vis[nx][ny][k] = 1;
                        q.push({nx, ny, k});
                    }
                }
            } else {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (check(nx, ny, m, n, s) && !vis[nx][ny][dir]) {
                    vis[nx][ny][dir] = 1;
                    q.push({nx, ny, dir});
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!cellVisited[i][j] && s.find({i, j}) == s.end())
                    ans++;
            }
        }
        return ans;
    }
};
