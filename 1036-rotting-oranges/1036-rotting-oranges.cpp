class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        
        // Push all initially rotten oranges into the queue
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                }
            }
        }
        
        int ans = 0;
        // Perform BFS
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            int x = p.first.first;
            int y = p.first.second;
            int t = p.second;
            ans = max(ans, t);
            
            // Check all 4 directions
            if(x - 1 >= 0 && grid[x-1][y] == 1) {
                q.push({{x-1, y}, t + 1});
                grid[x-1][y] = 2;
            }
            if(y - 1 >= 0 && grid[x][y-1] == 1) {
                q.push({{x, y-1}, t + 1});
                grid[x][y-1] = 2;
            }
            if(x + 1 < n && grid[x+1][y] == 1) {
                q.push({{x+1, y}, t + 1});
                grid[x+1][y] = 2;
            }
            if(y + 1 < m && grid[x][y+1] == 1) {
                q.push({{x, y+1}, t + 1});
                grid[x][y+1] = 2;
            }
        }
        
        // Check if any fresh oranges remain
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        
        return ans;
    }
};
