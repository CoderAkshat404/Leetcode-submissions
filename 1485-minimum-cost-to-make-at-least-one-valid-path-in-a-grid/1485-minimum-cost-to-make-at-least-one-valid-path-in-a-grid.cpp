class Solution {
public:
    bool check(int i,int j,vector<vector<int>>& grid){
        return (i<grid.size()) && (i>=0) && (j>=0) && (j<grid[0].size());
    }
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        deque<pair<int,int>> dq;
        vector<vector<int>> dis(n,vector<int>(m,1e9));
        dq.push_back({0,0});
        dis[0][0]=0;
        while(!dq.empty()){
            int i=dq.front().first;
            int j=dq.front().second;
            dq.pop_front();
            for(int k=0;k<4;k++){
                int ni=i+dx[k];
                int nj=j+dy[k];
                int dist=dis[i][j];
                if(k+1==grid[i][j]){
                    if(check(ni,nj,grid) && dist<dis[ni][nj]){
                        dis[ni][nj]=dist;
                        dq.push_front({ni,nj});
                    }
                }
                else{
                    if(check(ni,nj,grid) && dist+1<dis[ni][nj]){
                        dis[ni][nj]=dist+1;
                        dq.push_back({ni,nj});
                    }

                }

            }
        }
        return dis[n-1][m-1];
        
    }
};