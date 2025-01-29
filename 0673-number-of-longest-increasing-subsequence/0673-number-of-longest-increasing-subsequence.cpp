class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        vector<int> cnt(nums.size(),1);
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i] && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    cnt[i]=cnt[j];
                }
                else if(nums[j]<nums[i] && dp[j]+1==dp[i]){
                    cnt[i]+=cnt[j];
                }
            }
        
        }
        unordered_map<int,int> m;
        int maxi=INT_MIN;
        for(int i=0;i<dp.size();i++){
            m[dp[i]]+=cnt[i]; 
            maxi=max(maxi,dp[i]);  
        }
        if(count(dp.begin(),dp.end(),1)==nums.size()){
            return nums.size();
        }
        return m[maxi];
        
    }
};