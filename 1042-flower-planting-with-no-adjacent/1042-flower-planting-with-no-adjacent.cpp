class Solution {
public:
    void dfs(int & counter,int node,vector<int> &vis,vector<int>& ans,vector<vector<int>>&adj){
        ans[node-1]=(counter)%5;
        vis[node]=1;
        counter++;
        if(counter==5){
            counter=1;
        }
        for(auto i:adj[node]){
            if(!vis[i]){
                dfs(counter,i,vis,ans,adj);
            }
            else{
                vector<bool> nt(5,0);
                for(auto j:adj[node]){
                    nt[ans[j-1]]=true;
                }
                for(int j=1;j<=4;j++){
                    if(nt[j]==false){
                        ans[node-1]=j;
                        break;
                    }
                }

            }

        }
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n+1);
        for(int i=0;i<paths.size();i++){
            adj[paths[i][0]].push_back(paths[i][1]);
            adj[paths[i][1]].push_back(paths[i][0]);
        }
        vector<int> vis(n+1,0);
        vector<int> ans(n,0);
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                int counter=1;
                dfs(counter,i,vis,ans,adj);
            }
        }
        return ans;
        
    }
};