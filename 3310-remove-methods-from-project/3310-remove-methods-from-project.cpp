class Solution {
public:
    vector<int> vis;
    vector<vector<int>> adj;
    void dfs(int node){
        vis[node]=1;
        
        for(auto i:adj[node]){
            if(!vis[i]){
                dfs(i);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        adj=vector<vector<int>> (n);
        for(auto i:invocations){
            adj[i[0]].push_back(i[1]);
        }
        vis=vector<int> (n,0);
        dfs(k);
     
        bool flag=false;
        for(auto i:invocations){
            if(vis[i[1]]==1 && vis[i[0]]==0){
                flag=true;
                break;
            }
        }
        if(!flag){
            vector<int> ans;
            for(int i=0;i<n;i++){
                if(vis[i]==0){
                    ans.push_back(i);
                }
            }
            return ans;
        }
          vector<int> ans;
            for(int i=0;i<n;i++){
                
                    ans.push_back(i);
                

            }
        
        return ans;
    }
};