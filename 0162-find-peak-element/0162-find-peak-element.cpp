class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int lo=0;
        int hi=n-1;
        int ans=-1;
        while(lo<=hi){
            int m=hi-(hi-lo)/2;
            if(m==nums.size()-1 || (nums[m]>nums[m+1] && m!=nums.size()-1)){
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