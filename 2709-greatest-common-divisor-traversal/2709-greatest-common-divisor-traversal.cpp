class Solution {
public:
    int spf[100100];
    map<int,vector<int>> adj;
    vector<int> vis;
    vector<int> nums;
    int vis2[100100];
    void dfs(int node){
        vis[node]=1;
        int curr=nums[node];
        while(curr!=1){
            int x=spf[curr];
            if(vis2[x]==0){
                vis2[x]=1;
            for(auto i:adj[x]){
                if(!vis[i]){
                    dfs(i);
                }
            }
            }
            curr=curr/x;
        }
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        for(int i=0;i<100100;i++){
            spf[i]=i;
        }
        for(int i=2;i<100100;i++){
            vis2[i]=0;
            if(spf[i]==i){
                for(int j=2*i;j<100100;j+=i){
                    if(spf[j]==j){
                        spf[j]=i;
                    }
                }
            }
        }
        int n=nums.size();
        for(int i=0;i<n;i++){
            int curr=nums[i];
            while(curr!=1){
                int x=spf[curr];
                adj[x].push_back(i);
                curr=curr/x;
            }
        }
        vis.resize(n,0);
        this->nums=nums;
        dfs(0);
        for(auto i:vis){
            if(i==0){
                return false;
            }
        }
        return true;

        
        
        
    }
};