class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> cnt(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    if(dp[i]<dp[j]+1){
                        cnt[i]=cnt[j];
                        dp[i]=dp[j]+1;
                    } 
                    else if(dp[i]==dp[j]+1){
                        cnt[i]+=cnt[j];
                    }   
                }
            }
        }
        int maxi=INT_MIN;
        for(auto i:dp){
            maxi=max(maxi,i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi){
                ans+=cnt[i];
            }
        }
        if(maxi==1){
            return nums.size();
        }
        return ans;
        
        
    }
};