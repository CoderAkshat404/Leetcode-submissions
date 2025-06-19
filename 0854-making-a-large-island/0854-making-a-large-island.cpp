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
    bool check(int i,int j,vector<vector<int>>& grid){
        return (i>=0) && (i<grid.size()) && (j>=0) && (j<grid[0].size());
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        DSU ds(n*m);
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int number=(m*i)+j;
                    for(int k=0;k<4;k++){
                        int nr=i+dx[k];
                        int nc=j+dy[k];
                        int no=(nr*m)+nc;
                        if(check(nr,nc,grid) && grid[nr][nc]==1){
                            ds.unionbysize(number,no);
                        }
                    }
                }
            }
        }

        bool flag=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    flag=false;
                    break;
                }
            }
        }
        if(flag) return n*n;
        int maxi=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    unordered_set<int> s;
                    for(int k=0;k<4;k++){
                        int nr=i+dx[k];
                        int nc=j+dy[k];
                        int no=(nr*m)+nc;
                        if(check(nr,nc,grid) && grid[nr][nc]==1){
                            s.insert(ds.findparent(no));
                        }

                    }
                    int count=0;
                    for(auto l:s){
                        count+=ds.size[l];
                    }
                    maxi=max(maxi,count+1);

                }
            }
        }
      return maxi;  
    }
};