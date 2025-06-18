class DSU {
    public:
        vector<int> rank, parent, size;
        
        DSU(int n) {
            rank.resize(n + 1, 0);
            parent.resize(n + 1);
            size.resize(n + 1, 1);  
            
            for (int i = 0; i <= n; i++) {
                parent[i] = i;
            }
        }
    
        int findparent(int n) {
            if (n == parent[n]) return n;
            return parent[n] = findparent(parent[n]);
        }
    
        void addedge(int u, int v) {
            int pu = findparent(u);
            int pv = findparent(v);
            if (pu == pv) return;
    
            if (rank[pu] > rank[pv]) {
                parent[pv] = pu;
            } else if (rank[pu] < rank[pv]) {
                parent[pu] = pv;
            } else {
                parent[pu] = pv;
                rank[pv]++;
            }
        }
    
        void unionbysize(int u, int v) {
            int pu = findparent(u);
            int pv = findparent(v);
            if (pu == pv) return;
    
            if (size[pu] > size[pv]) {
                parent[pv] = pu;
                size[pu] += size[pv]; 
            } else {
                parent[pu] = pv;
                size[pv] += size[pu]; 
            }
        }
};



class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU ds(n);
        int cnt=0;
        for(int i=0;i<connections.size();i++){
            int v=connections[i][0];
            int u=connections[i][1];
            if(ds.findparent(v)!=ds.findparent(u)){
                ds.unionbysize(u,v);
                
            }
            else{
                cnt++;
            }
        }
        int needed=0;
        for(int i=0;i<n;i++){
            if(ds.findparent(i)==i){
                needed++;

            }
        }
        if(cnt>=needed-1){
            return needed-1;
        }
        return -1;
        
    }
};