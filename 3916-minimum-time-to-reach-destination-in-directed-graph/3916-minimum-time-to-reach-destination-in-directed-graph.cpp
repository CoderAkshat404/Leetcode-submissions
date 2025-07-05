class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,pair<int,int>>>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int st=edges[i][2];
            int end=edges[i][3];
            adj[u].push_back({v,{st,end}});
        }
        //time,node
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        vector<int> vis(n,0);
        while(!pq.empty()){
            int node=pq.top().second;
            int time=pq.top().first;
            if(node==n-1){
                return time;
            }
            pq.pop();
            if(vis[node]==1){
                continue;
            }
            vis[node]=1;
            for(auto i:adj[node]){
                int nnode=i.first;
                int start=i.second.first;
                int end=i.second.second;
                if(time>=start && time<=end){
                    pq.push({time+1,nnode});
                }
                else if(time<start){
                    pq.push({start+1,nnode});
                }
            }
        }

      return -1;  
    }
};