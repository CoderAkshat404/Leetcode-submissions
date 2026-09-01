class Solution {
public:
    int dp[101][5001];
    int solve(int i,int sum,vector<int>& nums){
        if(sum<0){
            return 1e9;
        }
        if(sum==0){
            return 0;
        }
        if(i>=nums.size()){
            return 1e9;
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
        int ans=1e9;
        ans=min(ans,solve(i+1,sum,nums));
        long long x=nums[i];
        int cnt=0;
        while(x<=sum){
            ans=min(ans,cnt+solve(i+1,sum-x,nums));
            x=x*2;
            cnt++;
        }
        x=nums[i];
        cnt=1;
        while(x>0){
            x=x/2;
            if(x==0) break;
            ans=min(ans,(cnt)+solve(i+1,sum-x,nums));
           
            cnt++;
        }
        return dp[i][sum]=ans;    
    }
    int minOperations(vector<int>& nums, int sum) {
        memset(dp,-1,sizeof(dp));
        
        int x= solve(0,sum,nums);
        if(x>=1e9) return -1;
        return x;
        
    }
};