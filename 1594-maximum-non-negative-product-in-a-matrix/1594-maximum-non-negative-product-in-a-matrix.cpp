using state=pair<long long,long long>;
vector<vector<int>> vis;
vector<vector<state>> dp;
int mod=1e9+7;
class Solution {
public:
    state solve(int i,int j,vector<vector<int>>& grid,int n,int m){
        if(i==n-1 && j==m-1){
            return {grid[i][j],grid[i][j]};
        }
        if(vis[i][j]==1) return dp[i][j];
        long long maxi=-1e18;
        long long mini=1e18;
        if(i+1<n){  
            state ch1=solve(i+1,j,grid,n,m);
            maxi=max(maxi,grid[i][j]*ch1.first);
            maxi=max(maxi,grid[i][j]*ch1.second);
            mini=min(mini,grid[i][j]*ch1.first);
            mini=min(mini,grid[i][j]*ch1.second);
        }
        if(j+1<m){
            state ch1=solve(i,j+1,grid,n,m);
            maxi=max(maxi,grid[i][j]*ch1.first);
            maxi=max(maxi,grid[i][j]*ch1.second);
            mini=min(mini,grid[i][j]*ch1.first);
            mini=min(mini,grid[i][j]*ch1.second);
        }
        vis[i][j]=1;
        return dp[i][j]={maxi,mini};


    }
    int maxProductPath(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        dp=vector<vector<state>>(n,vector<state>(m,{-1,-1}));
        vis=vector<vector<int>>(n,vector<int>(m,0));
        state x=solve(0,0,grid,n,m);
        if(x.first>=0){
            return (x.first)%mod;

        }
        return -1;

        
    }
};