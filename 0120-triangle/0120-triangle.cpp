class Solution {
public:
    int findans(vector<vector<int>>& triangle,vector<vector<int>> &dp,int i,int j){
        if(i>=triangle.size() && j>=triangle[i].size()){
            return INT_MAX;
        }
        if(i==triangle.size()-1){
            return triangle[i][j];
        }
        if(j>=triangle[i].size()){
            return INT_MAX;
        }
        if(dp[i][j]!=-INT_MAX){
            return dp[i][j];
        }
        dp[i][j]=min((triangle[i][j]+findans(triangle,dp,i+1,j)),(triangle[i][j]+findans(triangle,dp,i+1,j+1)));
        return dp[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp;
        for(int i=0;i<triangle.size();i++){
            int x=i+1;
            vector<int> v(x,-INT_MAX);
            dp.push_back(v);
        }

        int ans=findans(triangle,dp,0,0);
        return ans;
        
    }
};