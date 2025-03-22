class Solution {
public:
    void dfs(int node,vector<int>&vis,vector<vector<int>>&adj,int&countn, int & counte){
        vis[node]=1;
        countn++;
        vector<int> v=adj[node];
        counte+=v.size();
        for(auto i:v){
            if(!vis[i]){
                dfs(i,vis,adj,countn,counte);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int counte=0;
                int countn=0;
                dfs(i,vis,adj,counte,countn);
                cout<<counte<<" "<<countn<<endl;
                if(countn==(counte)*(counte-1)){
                    ans++;
                }
            }
        }
        return ans;
        
    }
};