class Solution {
public:
    int finalElement(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        if(nums[0]==maxi || nums.back()==maxi) return maxi;
        else{
            return max(nums[0],nums.back());
        }
        
    }
};