class Solution {
public:
    int maxi=-1e9;
    vector<int> vis;
    vector<int> c;
    vector<int> edges;
    void dfs(int node,int timer){
        vis[node]=2;
        c[node]=timer;
        if(edges[node]!=-1 &&vis[edges[node]]==2){
            maxi=max(maxi,c[node]-c[edges[node]]+1);
        }
        else if(edges[node]!=-1 && vis[edges[node]]==1){
            dfs(edges[node],timer+1);
        }
        vis[node]=3;

    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vis.resize(n,1);
        c.resize(n);
        this->edges=edges;
        for(int i=0;i<n;i++){
            if(vis[i]==1){
                dfs(i,0);
            }
        }
        if(maxi==-1e9) return -1;
        return maxi;

        
    }
};