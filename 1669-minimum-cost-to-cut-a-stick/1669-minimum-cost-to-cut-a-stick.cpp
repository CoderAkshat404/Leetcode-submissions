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
        int m=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(m+1,vector<int>(m+1,-1));

        int ans=findans(1,cuts.size()-2,cuts,dp);
        return ans;
        
    }
};