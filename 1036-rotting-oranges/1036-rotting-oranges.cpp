class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                    
                }
            }
        }
        int ans=0;
        while(!q.empty()){
            pair<pair<int,int>,int> p=q.front();
            q.pop();
            ans=max(ans,p.second);
            int x=p.first.first;
            int y=p.first.second;
            int t=p.second;
            if(x-1>=0){
                if(grid[x-1][y]==1){
                    q.push({{x-1,y},t+1});
                    vis[x-1][y]=2;
                    grid[x-1][y]=2;
                }
            }
            if(y-1>=0){
                if(grid[x][y-1]==1){
                    q.push({{x,y-1},t+1});
                    vis[x][y-1]=2;
                    grid[x][y-1]=2;
                }

            }
            if(x+1<n){
                if(grid[x+1][y]==1){
                    q.push({{x+1,y},t+1});
                    vis[x+1][y]=2;
                    grid[x+1][y]=2;
                }

            }
            if(y+1<m){
                if(grid[x][y+1]==1){
                    q.push({{x,y+1},t+1});
                    vis[x][y+1]=2;
                    grid[x][y+1]=2;
                }

            }
        }
        bool flag=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    flag=false;
                    break;
                }
            }
        }
        if(flag){
            return ans;
        }
        return -1;


        
    }
};