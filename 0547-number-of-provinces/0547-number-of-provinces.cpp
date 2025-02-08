class Solution {
public:
    void dfs(int node,vector<int>&vis,vector<vector<int>>&adj){
        if(!vis[node]){
            vis[node]=1;
            vector<int> v=adj[node];
            for(auto i:v){
                dfs(i,vis,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected.size();j++){
                if(isConnected[i][j]==1){
                    if(i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);}
                }
            }
        }
        vector<int> vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(i,vis,adj);
            }
        }
        return ans;
        
    }
};