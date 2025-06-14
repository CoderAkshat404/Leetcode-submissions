class Solution {
public:
    void dfs(vector<int>&vis, vector<vector<int>>&adj,int node){
        vis[node]=1;
        for(auto i:adj[node]){
            if(!vis[i]){
                dfs(vis,adj,i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);

                }
            }
        }
        int ans=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(vis,adj,i);
            }
        }
        return ans;
        
    }
};