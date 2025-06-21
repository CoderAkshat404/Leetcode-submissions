class Solution {
public:
    bool check(int i,int j,vector<vector<int>>& grid){
        return (i>=0) && (i<grid.size()) && (j>=0) && (j<grid[0].size());
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({grid[0][0],0,0});
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        while(!pq.empty()){
            int i=pq.top()[1];
            int j=pq.top()[2];
            int time=pq.top()[0];
            if(i==n-1 && j==m-1){
                return time;
            }
            if(vis[i][j]){
                pq.pop();
                continue;
            }
            vis[i][j]=1;
            pq.pop();
            for(int k=0;k<4;k++){
                int nr=i+dx[k];
                int nc=j+dy[k];
                if(check(nr,nc,grid) && time<=grid[nr][nc]){
                    pq.push({grid[nr][nc],nr,nc});
                }
                else if(check(nr,nc,grid) && time>=grid[nr][nc]){
                    pq.push({time,nr,nc});
                }
            }
        }

       return 0; 
    }
};