class Solution {
public:
    int counter=0;
    long long dfs(int node,int parent,vector<int>& cost,vector<vector<int>>&adj){
        vector<long long> v;
        for(auto i:adj[node]){
            if(i!=parent){
                v.push_back(dfs(i,node,cost,adj));
            }
        }
        if(v.size()==0){
            return cost[node];
        }
        long long maxi=-1e12;
        for(auto i:v){
            maxi=max(maxi,i);
        }
        for(auto i:v){
            if(i!=maxi){
                counter++;
            }
        }
        return cost[node]+maxi;
    }
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);

        }
        long long x=dfs(0,-1,cost,adj);
        return counter;

        
    }
};