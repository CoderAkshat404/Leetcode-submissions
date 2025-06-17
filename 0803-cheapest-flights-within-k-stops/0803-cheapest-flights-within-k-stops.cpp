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
            vector<int> t=q.front();
            q.pop();
            int stops=t[0];
            int node=t[1];
            int d=t[2];
            vector<pair<int,int>> v=adj[node];
            for(auto i:v){
                int nd=d+i.second;
                if(nd<dist[i.first]){
                    if(stops<=k){
                        dist[i.first]=nd;
                        q.push({stops+1,i.first,nd});
                    }
                }
            }

        }
        if(dist[dst]==1e9){
            return -1;
        }
        return dist[dst];
    }
};