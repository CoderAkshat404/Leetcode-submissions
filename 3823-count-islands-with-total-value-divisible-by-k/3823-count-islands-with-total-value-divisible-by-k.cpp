class Solution {
public:
    vector<int> dx;
    vector<int> dy;
    bool check(int i,int j,vector<vector<int>>& grid){
        return (i>=0) && (i<grid.size()) && (j>=0) && (j<grid[0].size()) && (grid[i][j]>0);
    }
    void dfs(int i,int j,vector<vector<int>> & vis,vector<vector<int>>& grid,long long  & sum){
        vis[i][j]=1;
        sum+=grid[i][j];
        for(int k=0;k<4;k++){
            int ni=i+dx[k];
            int nj=j+dy[k];
            if(check(ni,nj,grid) && !vis[ni][nj]){
                dfs(ni,nj,vis,grid,sum);
            }
        }
        
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        dx={1,0,-1,0};
        dy={0,1,0,-1};
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]>0){
                    long long sum=0;
                    dfs(i,j,vis,grid,sum);
                    if(sum%k==0 && sum!=0){
                        ans++;
                    }
                }
            }
        }
        return ans;
        
    }
};