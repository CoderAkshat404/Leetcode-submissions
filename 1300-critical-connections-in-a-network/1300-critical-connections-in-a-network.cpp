class Solution {
public:
    int timer;
    void dfs(int node,int parent,vector<int>&vis,vector<vector<int>>&adj,vector<vector<int>>&ans,vector<int>&ti,vector<int>& lo){
        vis[node]=1;
        ti[node]=timer;
         lo[node]=timer;
        timer++;
       
        for(auto i:adj[node]){
            if(!vis[i] && i!=parent){
                dfs(i,node,vis,adj,ans,ti,lo);
                lo[node]=min(lo[i],lo[node]);
                if(ti[node]<lo[i]){
                    ans.push_back({node,i});
                }
            }
            else if(vis[i]==1 && i!=parent){
                lo[node]=min(ti[i],lo[node]);
            }

        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        timer=1;
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> lo(n,0);
        vector<int> ti(n,0);
        vector<int> vis(n,0);
        vector<vector<int>> ans;
        dfs(0,-1,vis,adj,ans,lo,ti);
        return ans;

        
    }
};