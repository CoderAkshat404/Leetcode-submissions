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
    
        void unionBySize(int u, int v) {
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
    int removeStones(vector<vector<int>>& stones) {
        int n=0;
        int m=0;
        for(int i=0;i<stones.size();i++){
            n=max(n,stones[i][0]);
            m=max(m,stones[i][1]);
        }
        n++;
        m++;
        
        DSU ds(n+m);
        unordered_map<int,int> mp;
        for(int i=0;i<stones.size();i++){
                    int row=stones[i][0];
                    int col=stones[i][1]+n;
                     ds.addedge(row,col);
                     mp[row]=1;
                     mp[col]=1;
                    
        }
        int ans=0;
        for(auto i:mp){
            if(ds.findparent(i.first)==i.first){
            ans++;}
        }
        
        return stones.size()-ans;

        
    }
};