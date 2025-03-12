class Solution {
public:
bool dfs(int node,vector<vector<int>> &graph,vector<int>& vis,vector<int>&pathvis,vector<int> &safe)
    // Function to detect cycle in a directed graph.
    {
        vis[node]=1;
        pathvis[node]=1;
        vector<int> v=graph[node];
        for(auto i:v){
            if(!vis[i]){
                if(dfs(i,graph,vis,pathvis,safe)){
                    return true;
                }
     
            }
            else if(pathvis[i]){
                return true;
            }
        }
        safe[node]=1;
        pathvis[node]=0;
        return false;
        
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0);
        vector<int> pathvis(n,0);
        vector<int> safe(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
            dfs(i,graph,vis,pathvis,safe);
                
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(safe[i]){
                ans.push_back(i);
            }
        }
        return ans;
        
        // code here
    
        
    }
};