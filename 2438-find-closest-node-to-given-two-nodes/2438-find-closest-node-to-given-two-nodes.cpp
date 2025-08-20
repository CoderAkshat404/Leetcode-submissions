class Solution {
public:
    ;
    unordered_map<int,int> m2;
    void dfs(int node,vector<int>& edges,vector<int>&vis,int dist,unordered_map<int,int> &m1){
        if(node==-1){
            return;
        }
        if(vis[node]==1){
            return;
        }
        m1[node]=dist;
        vis[node]=1;
        dfs(edges[node],edges,vis,dist+1,m1);
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        unordered_map<int,int> m1;
        unordered_map<int,int> m2;
        vector<int> vis(n,0);
        dfs(node1,edges,vis,0,m1);
       vector<int> vis2(n,0);
        dfs(node2,edges,vis2,0,m2);
        int ans=1e9;
        int mini=1e9;
        for(auto i:m1){
            int node=i.first;
            int dist=i.second;
            // cout<<node<<" "<<dist<<endl;
            if(m2.find(node)!=m2.end()){
                dist=max(dist,m2[node]);
                if(dist<mini){
                    ans=node;
                    mini=dist;

                }
                if(dist==mini){
                    ans=min(ans,node);
                }
            }
            
        }
        if(ans==1e9){
            return -1;
        }
        return ans;


        
    }
};