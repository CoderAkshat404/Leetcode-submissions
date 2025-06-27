class Solution {
public:
    bool check(int i, int j, vector<string>& matrix) {
        return (i >= 0 && i < matrix.size() && j >= 0 && j < matrix[0].size() && matrix[i][j] != '#');
    }

    int minMoves(vector<string>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        
        unordered_map<char, vector<pair<int,int>>> mp;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (matrix[i][j] >= 'A' && matrix[i][j] <= 'Z')
                    mp[matrix[i][j]].push_back({i,j});

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        dist[0][0] = 0;
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            auto [d, i, j] = pq.top(); pq.pop();

            if (d > dist[i][j]) continue;

            // Normal 4-direction moves
            for (int k = 0; k < 4; ++k) {
                int ni = i + dx[k], nj = j + dy[k];
                if (check(ni, nj, matrix) && d + 1 < dist[ni][nj]) {
                    dist[ni][nj] = d + 1;
                    pq.push({dist[ni][nj], ni, nj});
                }
            }

            char ch = matrix[i][j];
            if (ch >= 'A' && ch <= 'Z') {
                for (auto [ti, tj] : mp[ch]) {
                    if (d < dist[ti][tj]) {
                        dist[ti][tj] = d ;
                        pq.push({dist[ti][tj], ti, tj});
                    }
                }
                mp[ch].clear(); 
            }
        }

        return dist[n-1][m-1] == 1e9 ? -1 : dist[n-1][m-1];
    }
};