class Solution {
public:
    vector<int> dx;
    vector<int> dy;
    string p;
    bool flag;
    bool check(int i,int j,vector<vector<char>>& board){
        return (i>=0) && (i<board.size()) && (j>=0) && (j<board[0].size());
    }
   void rec(int i,int j,vector<vector<char>>& board, string word,vector<vector<int>> &vis){
        if(flag) return;
        vis[i][j]=1;
        p.push_back(board[i][j]);
        if(word.length()==p.length()){
            if(p==word){
                flag=true;
            }
            vis[i][j]=0;
            p.pop_back();
            return;
        }
        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (check(ni, nj, board) && vis[ni][nj] == 0) {
                rec(ni, nj, board, word, vis);
            }
        }
        vis[i][j]=0;
        p.pop_back();

    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        dx={1,0,-1,0};
        dy={0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vector<vector<int>> vis(n,vector<int>(m,0));
                rec(i,j,board,word,vis);
            }
        }
        return flag;
    }
};