class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        #define int long long
        vector<int> m(k,1e18);
        int currsum=0;
        int ans=-1e18;
        m[k-1]=0;
        for(int i=0;i<nums.size();i++){
            currsum+=nums[i];
            if(nums.size()>=k-1){
                ans=max(ans,currsum-m[i%k]);
            }
            m[i%k]=min(m[i%k],currsum);
        }
        return ans;
        #undef int
        
    }
};