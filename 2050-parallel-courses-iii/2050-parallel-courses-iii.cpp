class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& r,vector<int>& time) {
        int ans=0;
        vector<int> indegree(n+1,0);
        vector<vector<int>> adj(n+1);
        for(int i=0;i<r.size();i++){
            int u=r[i][0];
            int v=r[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        vector<int> mt(n+1,0);
        queue<int> q;
        for(int i=1;i<=n;i++){
            if(indegree[i]==0){ 
            q.push(i);
            mt[i]=time[i-1];
            }
        }
        while(!q.empty()){
           int node=q.front();
           q.pop();
           for(auto i:adj[node]){
            mt[i]=max(mt[node]+time[i-1],mt[i]);
            indegree[i]--;
            if(indegree[i]==0){
                q.push(i);
            }
           }
        }
    for(int i=1;i<=n;i++){
        ans=max(ans,mt[i]);
    }
     return ans;   
    }
};