class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans=-1;
        int mini=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=mini){
                mini=nums[i];
            }
            else{
                ans=max(ans,nums[i]-mini);
            }

        }
        return ans;
        
    }
};