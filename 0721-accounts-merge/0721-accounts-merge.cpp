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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int> m;
        DSU ds(accounts.size());
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                if(m.find(accounts[i][j])!=m.end()){
                    ds.unionbysize(i,m[accounts[i][j]]);
                }
                else{
                    m[accounts[i][j]]=i;
                }
            }
        }
        int n=accounts.size();
        vector<vector<string>> ans(n);
        for(auto i:m){
            ans[ds.findparent(i.second)].push_back(i.first);
        }
        vector<vector<string>> fans;
        for(int i=0;i<n;i++){
            if(ans[i].size()>0){
                sort(ans[i].begin(),ans[i].end());
                ans[i].insert(ans[i].begin(),accounts[i][0]);
                fans.push_back(ans[i]);
            }
        }
        return fans;
        
    }
};