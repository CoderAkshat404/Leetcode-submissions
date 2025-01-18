class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int psum=0;
        int minp=0;
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            psum+=nums[i];
            ans=max(ans,psum-minp);
            minp=min(psum,minp);
           
        }
        return ans;
        
    }
};