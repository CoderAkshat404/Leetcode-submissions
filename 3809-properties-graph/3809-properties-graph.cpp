class Solution {
public:
    void dfs(int node, vector<vector<int>>&adj,vector<int>&vis){
        vis[node]=1;
        vector<int> v=adj[node];
        for(auto i:v){
            if(!vis[i]){
                dfs(i,adj,vis);
            }
        }
    }
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n=properties.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n-1;i++){
            unordered_set<int> s;
            for(int j=0;j< properties[i].size();j++){
                s.insert(properties[i][j]);
            }
            for(int j=i+1;j<n;j++){
                int x=0;
                unordered_set<int> s2;
                for(int p=0;p<properties[j].size();p++){
                     s2.insert(properties[j][p]);
                    
                }
                for(auto p:s2){
                    if(s.find(p)!=s.end()){
                        x++;
                    }
                }
                if(x>=k){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
    // for(auto i: adj){
    //     vector<int> v=i;
    //     for(auto j:v){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
        int ans=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(i,adj,vis);
            }
        }

        return ans;
    }
};