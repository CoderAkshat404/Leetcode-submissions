class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int lo=0;
        int hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int left=-1;
            int right=-1;
            if(mid-1>=0){
                left=nums[mid-1];
            }
            if(mid+1<n){
                right=nums[mid+1];
            }
            if(nums[mid]!=left && nums[mid]!=right){
                return nums[mid];
            }
            int leftc=0;
            int rightc=0;
            if(nums[mid]==left){
                rightc=n-mid-1;
                leftc=mid-1;
                if(leftc&1){
                    hi=mid-2;
                }
                else{
                    lo=mid+1;
                }
            }
            else{
                leftc=mid;
                rightc=n-mid-2;
                if(leftc&1){
                    hi=mid-1;
                }
                else{
                    lo=mid+2;
                }
            }
            
        }
        return -1;
    }
};