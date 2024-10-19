class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int diff=nums[nums.size()-1]-nums[0];
        if(diff<=2*k){
            return 0;
        }
        else{
            return diff-2*k;
        }
        
    }
};