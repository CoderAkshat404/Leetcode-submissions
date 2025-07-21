class Solution {
public:
    bool check(int i,int j,vector<vector<int>>& grid){
        return (i>=0) && (i<grid.size()) && (j>=0) && (j<grid[0].size()) && (grid[i][j]==0);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0] != 0 || grid[n-1][m-1] != 0)
            return -1;
        queue<pair<int,int>> q;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=1;
        q.push({0,0});
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int p=-1;p<=1;p++){
                for(int k=-1;k<=1;k++){
                    if(p==0 && k==0) continue;
                    int ni=i+p;
                    int nj=j+k;
                    if(check(ni,nj,grid)){
                        if(dist[ni][nj]>dist[i][j]+1){
                            dist[ni][nj]=dist[i][j]+1;
                            q.push({ni,nj});
                        }

                    }
                }
            }
        }
        if(dist[n-1][m-1]==1e9){
            return -1;
        }
        return dist[n-1][m-1];
        
    }
};