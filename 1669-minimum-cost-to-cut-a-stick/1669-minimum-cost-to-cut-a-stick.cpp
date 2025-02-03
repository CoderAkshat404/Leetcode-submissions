class Solution {
public:
    int findans(int i,int j,vector<int> &cuts,vector<vector<int>>&dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=1e9;
        for(int indx=i;indx<=j;indx++){
            ans=min(ans,findans(i,indx-1,cuts,dp)+findans(indx+1,j,cuts,dp)+cuts[j+1]-cuts[i-1]);
        }
        return dp[i][j]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        int m=cuts.size();
        vector<vector<int>> dp(m+2,vector<int>(m+2,0));
        for(int i=m;i>=1;i--){
            for(int j=0;j<=m-2;j++){
                if(i>j){
                    continue;
                }
                int ans=1e9;
                for(int indx=i;indx<=j;indx++){
                    ans=min(ans,dp[i][indx-1]+dp[indx+1][j]+cuts[j+1]-cuts[i-1]);
                }
                dp[i][j]=ans;
                
            }
        }
        return dp[1][cuts.size()-2];
        
        
    }
};