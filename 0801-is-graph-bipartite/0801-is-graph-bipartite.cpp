class Solution {
public:
    bool flag;
    void dfs(int node,vector<int>&vis,vector<vector<int>>& graph,vector<int> & color){
        vis[node]=1;
        for(auto i:graph[node]){
            if(!vis[i]){
                color[i]=1-color[node];
                dfs(i,vis,graph,color);
            }
            else{
                if(color[i]==color[node]){
                    flag=true;
                    return;
                }
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int m=graph[0].size();
        vector<int> vis(n,0);
        vector<int> color(n,-1);
        flag=false;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                color[i]=0;
                dfs(i,vis,graph,color);
            }
        }
        return !flag;
        
    }
};