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
    long long countPairs(int n, vector<vector<int>>& edges) {
        DSU ds(n);
        for(int i=0;i<edges.size();i++){
            ds.unionbysize(edges[i][0],edges[i][1]);
        }
        vector<int> v;
        for(int i=0;i<n;i++){
            if(ds.findparent(i)==i){
                v.push_back(ds.size[i]);
            }
        }
        long long suff=v.back();
        long long ans=0;
        for(int i=v.size()-2;i>=0;i--){
            ans=ans+1LL*v[i]*suff;
            suff+=v[i];
        }
        return ans;
        
    }
};