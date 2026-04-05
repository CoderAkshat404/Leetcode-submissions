class Solution {
public:
    bool ans=false;
    int n,m;
    string s="";
    vector<int> dx;
    vector<int> dy;
    bool check(int i,int j){
        return (i>=0 && i<n && j>=0 && j<m);
    }

    vector<vector<int>> vis;
    void solve(int i,int j,vector<vector<char>>& board, string& word){
        if(word.length()==s.length()){
            if(word==s){
                ans=true;
            }
            return;
        }
        s+=board[i][j];
        if(s==word) ans=true;
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int ni=i+dx[k];
            int nj=j+dy[k];
            
            if(check(ni,nj) && !vis[ni][nj]){
                solve(ni,nj,board,word);
            }
        }
        s.pop_back();
        vis[i][j]=0;
    }
    bool exist(vector<vector<char>>& board, string word) {
        dx={1,0,-1,0};
        dy={0,1,0,-1};
        n=board.size();
        m=board[0].size();
        
        vis=vector<vector<int>> (n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                solve(i,j,board,word);
            }
        }
        return ans;
        
        
        
    }
};