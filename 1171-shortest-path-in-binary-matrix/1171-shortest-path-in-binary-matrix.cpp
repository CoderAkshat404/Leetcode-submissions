class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]!=0){
            return -1;
        }
        queue<pair<int,pair<int,int>>> q;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        q.push({0,{0,0}});
        while(!q.empty()){
            int r=q.front().second.first;
            int c=q.front().second.second;
            int dista=q.front().first;
            q.pop();
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nr=r+i;
                    int nc=c+j;
                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==0 ){
                        if(dist[nr][nc]>1+dista){
                            dist[nr][nc]=1+dista;
                            q.push({1+dista,{nr,nc}});
                        }
                    }
                }
            }
        }
        if(dist[n-1][m-1]==1e9){
            return -1;
        }
        return dist[n-1][m-1]+1;

        
    }
};