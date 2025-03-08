class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>& board,int n,int m){
        if(i+1<n && vis[i+1][j]==0 && board[i+1][j]=='O'){
             vis[i+1][j]=1;
            dfs(i+1,j,vis,board,n,m);
           
        }
        if(j+1<m && vis[i][j+1]==0 && board[i][j+1]=='O'){
            vis[i][j+1]=1;
            dfs(i,j+1,vis,board,n,m);
            
        }
        if(i-1>=0 && vis[i-1][j]==0 && board[i-1][j]=='O'){
            vis[i-1][j]=1;
            dfs(i-1,j,vis,board,n,m);
            
        }
         if(j-1>=0 && vis[i][j-1]==0 && board[i][j-1]=='O'){
             vis[i][j-1]=1;
            dfs(i,j-1,vis,board,n,m);
           
        }




    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                vis[i][0]=1;
                dfs(i,0,vis,board,n,m);
                
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][m-1]=='O'){
                vis[i][m-1]=1;
                dfs(i,m-1,vis,board,n,m);
                
            }
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                vis[0][i]=1;
                dfs(0,i,vis,board,n,m);
                
            }
        }
        for(int i=0;i<m;i++){
            if(board[n-1][i]=='O'){
                vis[n-1][i]=1;
                dfs(n-1,i,vis,board,n,m);
                
            }
        }
       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0){
                    board[i][j]='X';
                }
                else{
                    board[i][j]='O';
                }
            }
        }


        
    }
};