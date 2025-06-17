class Solution {
public:
    int networkDelayTime(vector<vector<int>>& edges, int V, int k) {
        vector<vector<pair<int,int>>> adj(V+1);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int dist=edges[i][2];
            adj[u].push_back({v,dist});
        }
        vector<int> dist(V+1,1e9);
        queue<int> q;
        q.push(k);
        dist[k]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto i:adj[node]){
                if(dist[i.first]>dist[node]+i.second){
                    dist[i.first]=dist[node]+i.second;
                    q.push(i.first);
                }
            }
        }
        int maxi=-1e9;
        for(int i=1;i<V+1;i++){
            maxi=max(maxi,dist[i]);
        }
        if(maxi==1e9){
            return -1;
        }
        return maxi;
    
        
    }
};