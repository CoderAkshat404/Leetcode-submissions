class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=1;
        int mini=1e9;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            mini=min(mini,nums[i]);
            if(nums[i]-mini>k){
                mini=nums[i];
                ans++;
            }
        }
        return ans;
        
    }
};