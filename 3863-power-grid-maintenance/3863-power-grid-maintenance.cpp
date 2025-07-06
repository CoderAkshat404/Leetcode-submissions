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
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU ds(c);
        unordered_map<int,bool> m;
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            if(ds.findparent(u)!=ds.findparent(v)){
                ds.unionbysize(u,v);
            }
        }
        vector<set<int>> v(c+1);
        for(int i=1;i<=c;i++){
            int x=ds.findparent(i);
            v[x].insert(i);
        }
       
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int type=queries[i][0];
            int tower=queries[i][1];
            if(type==1){
                int x=ds.findparent(tower);
                if(v[x].find(tower)!=v[x].end()){
                    ans.push_back(tower);
                }
                else if(v[x].size()==0){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(*v[x].begin());
                }
            }
            else{
                int x=ds.findparent(tower);
                v[x].erase(tower);

            }
            
        }
      return ans;  
    }
};