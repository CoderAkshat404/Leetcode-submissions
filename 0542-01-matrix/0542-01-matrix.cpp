class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                    ans[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int d=q.front().second;
            q.pop();
            if(x-1>=0){
                if(vis[x-1][y]==0){
                    vis[x-1][y]=1;
                    q.push({{x-1,y},d+1});
                    ans[x-1][y]=d+1;
                }
            }
            if(y-1>=0){
                if(vis[x][y-1]==0){
                    vis[x][y-1]=1;
                    q.push({{x,y-1},d+1});
                    ans[x][y-1]=d+1;
                }
            }
            if(x+1<n){
                if(vis[x+1][y]==0){
                    vis[x+1][y]=1;
                    q.push({{x+1,y},d+1});
                    ans[x+1][y]=d+1;
                }
            }
            if(y+1<m){
                if(vis[x][y+1]==0){
                    vis[x][y+1]=1;
                    q.push({{x,y+1},d+1});
                    ans[x][y+1]=d+1;
                }
            }
        }
        return ans;

        
    }
};