class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n+1);
        vector<vector<pair<int,int>>> rdj(n+1);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
            rdj[v].push_back({u,w});
        }
        vector<int> dist(n+1,1e9);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,0,0});
        dist[0]=0;
        while(!pq.empty()){
            int dis=pq.top()[0];
            int node=pq.top()[1];
            int mode=pq.top()[2];
            pq.pop();
            for(auto i:adj[node]){
                if(i.second+dist[node]<dist[i.first]){
                    dist[i.first]=i.second+dist[node];
                    pq.push({dist[i.first],i.first,0});
                }
            }
            
                for(auto i:rdj[node]){
                if(2*i.second+dist[node]<dist[i.first]){
                    dist[i.first]=2*i.second+dist[node];
                    pq.push({dist[i.first],i.first,1});
                }
            

            }
        }
        if(dist[n-1]==1e9){
            return -1;
        }
        return dist[n-1];

        
    }
};