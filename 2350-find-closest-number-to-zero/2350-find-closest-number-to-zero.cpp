class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int mini=INT_MAX;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(abs(nums[i])<mini){
                ans=nums[i];
                mini=abs(nums[i]);
            }
            else if(abs(nums[i])==mini){
                if(nums[i]>0){
                    ans=nums[i];
                }
            }
        }
        return ans;
        
    }
};