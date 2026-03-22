class Solution {
public:
    int dp[40][100100];
    int solve(int i,int xori,vector<int>& nums, int target){
        if(i==nums.size()){
            if(xori==target){
                return 0;
            }
            return 1e9;
        }
        if(dp[i][xori]!=-1){
            return dp[i][xori];
        }
        int ch1=solve(i+1,(xori ^ nums[i]),nums,target);
        int ch2=1+solve(i+1,xori,nums,target);
        return dp[i][xori]=min(ch1,ch2);
        
    }
    int minRemovals(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        int x= solve(0,0,nums,target);
        if(x>50){
            return -1;
        }
        return x;
        
    }
};