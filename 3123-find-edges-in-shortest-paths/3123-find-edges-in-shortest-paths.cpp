class Solution {
public:
    vector<int> findsor(int src,int n, vector<vector<int>>& edges){
        vector<vector<pair<int,int>>> adj(n+1);
        vector<int> dist(n+1,1e9);
        vector<int> vis(n+1,0);
        for(auto i:edges){
            int u=i[0];
            int v=i[1];
            int w=i[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,src});
        dist[src]=0;
        while(!pq.empty()){
            int node=pq.top().second;
            int w=pq.top().first;
            pq.pop();
            if(vis[node]) continue;
            vis[node]=1;
            for(auto i:adj[node]){
                if(dist[i.first]>i.second+w){
                    dist[i.first]=i.second+w;
                    pq.push({dist[i.first],i.first});
                }
            }
        }
        return dist;
    }
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<int> v1=findsor(0,n,edges);
        vector<int> v2=findsor(n-1,n,edges);
        vector<bool> ans;
        for(auto i:edges){
            int u=i[0];
            int v=i[1];
            int w=i[2];
            if((v1[u]+v2[v]+w==v1[n-1]) || (v1[v]+v2[u]+w==v1[n-1])){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }

        }
        return ans;
    }
};