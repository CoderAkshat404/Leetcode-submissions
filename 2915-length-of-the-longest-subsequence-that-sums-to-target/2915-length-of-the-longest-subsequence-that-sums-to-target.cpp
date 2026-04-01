class Solution {
public:
    int dp[1001][1001];
    int solve(int i,vector<int>& nums, int target){
        if(target==0) return 0; 
        if(i>=nums.size()) return -1e9;
        if(dp[i][target]!=-1) return dp[i][target];
        int ch1=solve(i+1,nums,target);
        int ch2=-1e9;
        if(nums[i]<=target){
            ch2=1+solve(i+1,nums,target-nums[i]);

        }
        return dp[i][target]=max(ch1,ch2);

    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        int x= solve(0,nums,target);
        if(x<0){
            return -1;
        }
        return x;
        
    }
};