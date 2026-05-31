class Solution {
public:
    vector<int> cantake;
    int dp[1001][1501];
    int n;
    int solve(int i,int budget,vector<vector<int>>& items){
        if(i>=n) return 0;
        if(dp[i][budget]!=-1) return dp[i][budget];
        int ans=0;
        ans=max(ans,solve(i+1,budget,items));
        if(items[i][1]<=budget){
            ans=max(ans,1+solve(i,budget-items[i][1],items));
            if(cantake[i]>=1)
                ans=max(ans,1+cantake[i]+solve(i+1,budget-items[i][1],items));
        }
        return dp[i][budget]=ans;


    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        n=items.size();
        cantake.resize(n,0);
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            int curr=items[i][0];
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(items[j][0]%curr==0){
                    cantake[i]+=1;
                }
            }
        }
        return solve(0,budget,items);
        
    }
};