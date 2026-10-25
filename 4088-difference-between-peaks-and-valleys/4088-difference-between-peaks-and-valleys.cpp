class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        int sp=0;
        int sv=0;
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
                sp+=nums[i];
            }
            else if(nums[i]<nums[i-1] && nums[i]<nums[i+1]){
                sv+=nums[i];
            }
        }
        return sp-sv;
        
    }
};