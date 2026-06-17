class Solution {
public:
    vector<int> sums;
    int n;
    int dp[2001][2001][3];
    int solve(int l,int r,int i,vector<int>& nums){
        if(r-l+1<2) return 0;
        int ans=0;
        if(dp[l][r][i]!=-1) return dp[l][r][i];
        if(nums[l]+nums[l+1]==sums[i]){
            ans=max(ans,1+solve(l+2,r,i,nums));
        }
        if(nums[l]+nums[r]==sums[i]){
            ans=max(ans,1+solve(l+1,r-1,i,nums));
        }
        if(nums[r]+nums[r-1]==sums[i]){
            ans=max(ans,1+solve(l,r-2,i,nums));
        }
        return dp[l][r][i]=ans;

    }
    int maxOperations(vector<int>& nums) {
        n=nums.size();
        sums.push_back(nums[0]+nums[1]);
        sums.push_back(nums[0]+nums.back());
        sums.push_back(nums[nums.size()-1]+nums[nums.size()-2]);
        memset(dp,-1,sizeof(dp));
        return max(solve(0,nums.size()-1,0,nums),max(solve(0,nums.size()-1,1,nums),solve(0,nums.size()-1,2,nums)));
        
    }
};