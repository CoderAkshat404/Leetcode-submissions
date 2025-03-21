#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> adj(n);
        
        for (auto& road : roads) {
            int u = road[0], v = road[1], time = road[2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time}); // Ensure bidirectional edges
        }
        
        vector<long long> dist(n, 1e18);  // Change to long long
        vector<int> ways(n, 0);
        ways[0] = 1;
        dist[0] = 0;
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, 0});
        
        while (!pq.empty()) {
            long long time = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for (auto& [next, travelTime] : adj[node]) {
                long long newDist = time + travelTime;  // Use long long
                
                if (newDist < dist[next]) {
                    dist[next] = newDist;
                    ways[next] = ways[node];
                    pq.push({newDist, next});
                } else if (newDist == dist[next]) {
                    ways[next] = (ways[next] + ways[node]) % MOD;
                }
            }
        }
        
        return ways[n - 1];
    }
};
