class Solution {
public:
    long long dp[100100][2];
    long long total;
    long long n;
    long long solve(long long i,long long changes,vector<int>& nums){
        if(i>=n){
            
            return 0;
            
        }
        if(dp[i][changes]!=-1){
            return dp[i][changes];
        }
        long long ans=1e18;
        if(i+1<n){
            long long maxi=nums[i-1];
            maxi=max(maxi,(long long)nums[i+1]);
            if(nums[i]<=maxi){
                ans=min(ans,maxi-nums[i]+1+solve(i+2,changes,nums));
            }
            else{
                ans=ans=min(ans,solve(i+2,changes,nums));
            }
        }
        if(changes>0){
        ans=min(ans,solve(i+1,changes-1,nums));}
        return dp[i][changes]=ans;

    }
    long long minIncrease(vector<int>& nums) {
        n=nums.size();
        total=n/2;
        if(n%2==0){
            total--;
        }
        memset(dp,-1,sizeof(dp));
        return solve(1,1,nums);
        
    }
};