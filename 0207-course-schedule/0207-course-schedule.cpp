class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        for(int i=0;i< prerequisites.size();i++){
            int x= prerequisites[i][1];
            int y= prerequisites[i][0];
            adj[x].push_back(y);
        }
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            vector<int> v=adj[i];
            for(auto j:v){
                indegree[j]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node=q.front();
            topo.push_back(q.front());
            q.pop();
            vector<int> v=adj[node];
            for(auto i:v){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
        if(topo.size()==n){
            return true;
        }
        return false;
        
    }
};