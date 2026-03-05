class Solution {
public:
    int dp[101][101];
    bool valid(int i,int j,vector<int>& nums, int m){
        if(i==j){
            return true;
        }
        int sum=0;
        for(int idx=i;idx<=j;idx++){
            sum+=nums[idx];
        }
        return sum>=m;
    }
    bool solve(int i,int j,vector<int>& nums, int m){
        if(i==j){
            return true;
        }
        if(!valid(i,j,nums,m)) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        bool ans=false;
        for(int idx=i;idx<j;idx++){
            bool ans1=solve(i,idx,nums,m);
            bool ans2=solve(idx+1,j,nums,m);
            if(ans1 && ans2){
                ans=true;
                break;
            }
        }
        return dp[i][j]=ans;
        
    }
    bool canSplitArray(vector<int>& nums, int m) {
        if(nums.size()<=2){
            return true;
        }
        memset(dp,-1,sizeof(dp));
        return solve(0,nums.size()-1,nums,m);
        
    }
};