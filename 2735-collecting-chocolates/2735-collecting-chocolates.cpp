class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        vector<int> temp=nums;
        int n=nums.size();
        long long ans=1e18;
        long long sum=0;
        for(auto i:nums){
            sum+=i;
        }
        ans=min(ans,sum);
        for(int i=0;i<n;i++){
            int y=nums[0];
            nums.erase(nums.begin());
            nums.push_back(y);
            sum=0;
            for(int j=0;j<nums.size();j++){
                temp[j]=min(nums[j],temp[j]);
                sum+=temp[j];
            }
            sum+=x*1LL*(i+1);
            ans=min(ans,sum);
        }
    
        return ans;
    }
};