class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int  n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                vis[i][0]=1;
                q.push({i,0});
                
            }
        }
        for(int i=0;i<n;i++){
            if(grid[i][m-1]==1){
                vis[i][m-1]=1;
                q.push({i,m-1});
                
            }
        }
        for(int i=0;i<m;i++){
            if(grid[0][i]==1){
                vis[0][i]=1;
                q.push({0,i});
                
            }
        }
        for(int i=0;i<m;i++){
            if(grid[n-1][i]==1){
                vis[n-1][i]=1;
                q.push({n-1,i});
                
                
            }
        }
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            if(i+1<n && vis[i+1][j]==0 && grid[i+1][j]==1){
             vis[i+1][j]=1;
            q.push({i+1,j});
           
        }
        if(j+1<m && vis[i][j+1]==0 && grid[i][j+1]==1){
            vis[i][j+1]=1;
            q.push({i,j+1});
            
        }
        if(i-1>=0 && vis[i-1][j]==0 && grid[i-1][j]==1){
            vis[i-1][j]=1;
            q.push({i-1,j});
            
        }
         if(j-1>=0 && vis[i][j-1]==0 && grid[i][j-1]==1){
             vis[i][j-1]=1;
            q.push({i,j-1});
        }
        }

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    ans++;
                }
            }
        }
        return ans;



    }

};