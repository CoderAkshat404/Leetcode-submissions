class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int dist[n+1][m+1][5][k+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int p=0;p<5;p++){
                    for(int q=0;q<=k;q++){
                        dist[i][j][p][q]=1e9;
                    }
                }
            }
        }
        int vis[n+1][m+1][5][k+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int p=0;p<5;p++){
                    for(int q=0;q<=k;q++){
                        vis[i][j][p][q]=0;
                    }
                }
            }
        }
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        int dx[]={0,0,1,0,-1};
        int dy[]={0,1,0,-1,0};
        pq.push({grid[0][0],0,0,0,0});
        dist[0][0][0][0]=0;
        while(!pq.empty()){
            int cost=pq.top()[0];
            int x=pq.top()[1];
            int y=pq.top()[2];
            int dir=pq.top()[3];
            int turns=pq.top()[4];
            pq.pop();
            if(x==n-1 && y==m-1) return cost;
            if(vis[x][y][dir][turns]) continue;
            vis[x][y][dir][turns]=1;
            for(int i=1;i<=4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<m){
                    int nturns=turns;
                    if(i!=dir && dir!=0){
                        nturns++;
                    }
                    if(nturns>k) continue;
                    if(!vis[nx][ny][i][nturns] && dist[nx][ny][i][nturns]>cost+grid[nx][ny]){
                        dist[nx][ny][i][nturns]=cost+grid[nx][ny];
                        pq.push({cost+grid[nx][ny],nx,ny,i,nturns});
                    }
                }
            }
        }

        return -1;



        
    }
};