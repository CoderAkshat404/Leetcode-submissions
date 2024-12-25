class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo=0;
        int hi=nums.size()-1;
        int ans=0;
        while(lo<=hi){
            int m=lo+(hi-lo)/2;
            if(nums[m]<nums[0]){
                ans=m;
                hi=m-1;
            }
            else{
                lo=m+1;
            }
        }
        return nums[ans];
        
    }
};