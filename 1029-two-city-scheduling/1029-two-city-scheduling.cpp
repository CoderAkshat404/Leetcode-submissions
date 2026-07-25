class Solution {
public:
    int n;
    int dp[101][101][101];
    vector<vector<int>>cost;
    int solve(int i,int n1,int n2){
        if(i>=2*n){
            if(n1==n && n2==n) return 0;
            return 1e9;
        }
        if(dp[i][n1][n2]!=-1) return dp[i][n1][n2]; 
        int ans=1e9;
        
        ans=min(ans,cost[i][0]+solve(i+1,n1+1,n2));
        ans=min(ans,cost[i][1]+solve(i+1,n1,n2+1));
        return dp[i][n1][n2]=ans;
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
      
        this->cost=costs;
          n=cost.size()/2;
          memset(dp,-1,sizeof(dp));
        return solve(0,0,0);
    
        
    }
};