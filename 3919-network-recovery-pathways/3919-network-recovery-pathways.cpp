class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        #define int long long
        int n=online.size();
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
        }
        int maxi=INT_MIN;
        if(online[0]==false || online[n-1]==false){
            return -1;
        }
    priority_queue<vector<int>> pq;
        pq.push({(int)1e9,0,0});
        while(!pq.empty()){
            int dist=pq.top()[1];
            int node=pq.top()[2];
            int mintillnow=pq.top()[0];
            pq.pop();
            if(dist>k){
                continue;
            }
            if(node==n-1){
                maxi=max(maxi,mintillnow);
                break;
            }
            for(auto i:adj[node]){
                if(online[i.first]){
                    int x=min(mintillnow,i.second);
                    pq.push({x,dist+i.second,i.first});
                }
            }
        }
        if(maxi==INT_MIN){
            return -1;
        }
        return maxi;
        #undef int
        
        
    }
};