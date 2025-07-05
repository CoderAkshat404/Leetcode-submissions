class Solution {
public:
    int dp[302][302];
    int solve(int i,int j,vector<int>& nums){
        if(i>j) return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        for(int k=i;k<=j;k++){
            ans=max(ans,nums[k]*nums[i-1]*nums[j+1]+solve(i,k-1,nums)+solve(k+1,j,nums));
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(1,n-2,nums);
        
    }
};