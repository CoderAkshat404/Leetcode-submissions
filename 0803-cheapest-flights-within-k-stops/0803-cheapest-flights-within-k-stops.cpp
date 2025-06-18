class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int dist=flights[i][2];
            adj[u].push_back({v,dist});
        }
        vector<int> dist(n,1e9);
        queue<vector<int>> q;
        dist[src]=0;
        q.push({0,src,0});
        while(!q.empty()){
            int st=q.front()[2];
            int node=q.front()[1];
            int d=q.front()[0];
            q.pop();
            for(auto i:adj[node]){
                if(st<=k){
                    if(dist[i.first]>d+i.second){
                    dist[i.first]=min(d+i.second,dist[i.first]);
                    q.push({dist[i.first],i.first,st+1});}
                }
            }

        }
        if(dist[dst]==1e9){
            return -1;
        }
        return dist[dst];
    }
};