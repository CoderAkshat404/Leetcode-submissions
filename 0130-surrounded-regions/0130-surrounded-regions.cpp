class Solution {
public:
bool check(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& vis){
        return (i<grid.size()) &&(i>=0) &&(j<grid[0].size()) &&(j>=0) &&(grid[i][j]=='O' ) &&(vis[i][j]==0);
    }
    void solve(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        int r[]={0,n-1};
        int c[]={0,m-1};
        int dx[]={1,0,-1,0};
        int dy[]={0,1,0,-1};
        for(int i=0;i<2;i++){
            for(int j=0;j<m;j++){
                if(grid[r[i]][j]=='O'){
                    q.push({r[i],j});
                    vis[r[i]][j]=1;
                }
            }
        }
        for(int i=0;i<2;i++){
            for(int j=1;j<n-1;j++){
                if(grid[j][c[i]]=='O'){
                    q.push({j,c[i]});
                    vis[j][c[i]]=1;
                }
            }
        }
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int ni=i+dx[k];
                int nj=j+dy[k];
                if(check(ni,nj,grid,vis)){
                    q.push({ni,nj});
                    vis[ni][nj]=1;
                }
            }

        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='O' && vis[i][j]==0){
                    grid[i][j]='X';
                }
            }
        }
       
        
    }
};