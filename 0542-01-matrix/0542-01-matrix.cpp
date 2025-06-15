class Solution {
public:
    bool check(int i,int j,vector<vector<int>>& mat,vector<vector<int>>&vis){
        return (i<mat.size() && i>=0 && j<mat[0].size() && j>=0 && vis[i][j]==0 && mat[i][j]==1);
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        int dx[]={1,0,-1,0};
        int dy[]={0,1,0,-1};
        vector<vector<int>> dis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int d=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int ni=i+dx[k];
                int nj=j+dy[k];
                int nd=d+1;
                if(check(ni,nj,mat,vis)){
                    vis[ni][nj]=1;
                    dis[ni][nj]=nd;
                    q.push({{ni,nj},nd});
                }
            }

        }
        return dis;
        
    }
};