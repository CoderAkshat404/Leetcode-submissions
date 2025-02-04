class Solution {
public:
    int findans(int i,int j,vector<int>& nums,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=-1e9;
        for(int indx=i;indx<=j;indx++){
            ans=max(ans,nums[i-1]*nums[j+1]*nums[indx]+findans(i,indx-1,nums,dp)+findans(indx+1,j,nums,dp));
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
        int ans=findans(1,nums.size()-2,nums,dp);
        return ans;
        
    }
};