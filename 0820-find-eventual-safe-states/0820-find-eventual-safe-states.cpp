class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                adj[graph[i][j]].push_back(i);
                indegree[i]++;
            }
        }
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                ans.push_back(i);
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto i:adj[node]){
                indegree[i]--;
                if(indegree[i]==0){
                    ans.push_back(i);
                    q.push(i);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;

        
    }
};