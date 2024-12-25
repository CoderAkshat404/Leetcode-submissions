class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo=0;
        int hi=nums.size()-1;
        int ans=nums.size();
        while(lo<=hi){
            int m=hi-(hi-lo)/2;
            if(nums[m]>=target){
                ans=m;
                hi=m-1;
            }
            else{
                lo=m+1;
            }
        }
        return ans;
        
    }
};