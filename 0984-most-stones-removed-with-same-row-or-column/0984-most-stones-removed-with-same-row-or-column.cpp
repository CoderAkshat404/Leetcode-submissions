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
    int removeStones(vector<vector<int>>& stones) {
        int n=INT_MIN;
        int m=INT_MIN;
        for(auto i: stones){
            n=max(n,i[0]);
            m=max(m,i[1]);
        }
        n++;
        m++;
        DSU ds(n+m);
          unordered_map<int,bool> mp;
        for(auto i:stones){
            ds.unionbysize(i[0],i[1]+n);
             mp[i[0]]=true;
             mp[i[1]+n]==true;
        }
        int x=0;
      
        for(auto i:mp){
            if(ds.findparent(i.first)==i.first){
               
                x++;
            }
            
                
        }
        return stones.size()-x;
        
    }
};