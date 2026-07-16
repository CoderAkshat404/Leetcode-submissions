class Solution {
public:
    map<vector<vector<int>>,int> vis;
    vector<vector<int>> fin;
    vector<int> dx={0,0,1,-1};
    vector<int> dy={1,-1,0,0};
    int solve(int r,int c,vector<vector<int>>&board){
        queue<pair<vector<int>,vector<vector<int>>>> q;
        q.push({{0,r,c},board});
        while(!q.empty()){
            int steps=q.front().first[0];
            int x=q.front().first[1];
            int y=q.front().first[2];
            auto b=q.front().second;
            q.pop();
            if(b==fin){
                return steps;
            }
            if(vis[b]){
                continue;
            }
            vis[b]=1;
            for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
                if(nx>=0 && nx<2 && ny>=0 && ny<3){
                    swap(b[x][y],b[nx][ny]);
                    q.push({{steps+1,nx,ny},b});
                    swap(b[x][y],b[nx][ny]);
                }
            }

        }
        return 1e9;
       


    }
    int slidingPuzzle(vector<vector<int>>& board) {
        int x=-1;
        int y=-1;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==0){
                    x=i;
                    y=j;
                    break;
                }

            }
            if(x!=-1) break;
        }
        fin={{1,2,3},{4,5,0}};
        int ans=solve(x,y,board);
        if(ans>=1e9) return -1;
        return ans;
        
    }
};