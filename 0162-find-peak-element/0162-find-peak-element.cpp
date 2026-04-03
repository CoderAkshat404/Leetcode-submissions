class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        nums.push_back(INT_MIN);
        int lo=0;
        int hi=n-1;
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]>nums[mid+1]){
                ans=mid;
                hi=mid-1;

            }
            else{
                lo=mid+1;
            }

        }
        return ans;
        
    }
};