class DSU{
    vector<int> rank,parent,size;
    public:
    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i; 
            size[i]=i;
        }
    }
    int findparent(int n){
        if(n==parent[n]){
            return n;
        }
        return parent[n]=findparent(parent[n]);
    }
    void addedge(int u,int v){
        int pu=findparent(u);
        int pv=findparent(v);
        if(pu==pv){
            return;
        }
        if(rank[pu]>rank[pv]){
            parent[pv]=pu;
        }
        else if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else{
            parent[pu]=pv;
            rank[pv]++;

        }
    }
    void DSUBYsize(int u,int v){
        int pu=findparent(u);
        int pv=findparent(v);
        if(pu==pv){
            return;
        }
        if(size[pu]>size[pv]){
            parent[pv]=pu;
            size[pv]+=size[pu];
        }
        else{
            parent[pu]=pv;
            size[pu]+=size[pv];

        }

    }
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int> m;
        int n=accounts.size();
        DSU ds(n);
        
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(m.find(accounts[i][j])!=m.end()){
                    ds.addedge(i,m[accounts[i][j]]);
                    cout<<"here for i="<<i<<"j="<<j<<endl;
                }
                m[accounts[i][j]]=i;
            }
        }
        // cout<<ds.findparent(1)<<endl;
        vector<vector<string>> ans(n);
        for(auto i:m){
            ans[ds.findparent(i.second)].push_back(i.first);
        }
        vector<vector<string>> finans;
        for(int i=0;i<n;i++){
            if(ans[i].size()!=0){
                sort(ans[i].begin(),ans[i].end());
                ans[i].insert(ans[i].begin(),accounts[i][0]);
                finans.push_back(ans[i]);
            }


        }
        return finans;


        
    }
};