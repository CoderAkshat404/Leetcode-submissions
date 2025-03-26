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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU ds(n);
        int extra=0;
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            if(ds.findparent(u)==ds.findparent(v)){
                extra++;
            }
            else{
                ds.addedge(u,v);
            }
        }
        int nc=0;
        for(int i=0;i<n;i++){
            if(ds.findparent(i)==i){
                nc++;
            }
        }
        if(extra>=nc-1){
            return nc-1;
        }
        return -1;

        
    }
};