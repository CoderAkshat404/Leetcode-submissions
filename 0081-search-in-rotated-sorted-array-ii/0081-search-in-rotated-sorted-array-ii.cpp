class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int lo=0;
        int hi=n-1;
        while(lo<=hi){
            cout<<lo<<" "<<hi<<endl;
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target){
                return true;
            }
            if(nums[mid]==nums[lo] && nums[hi]==nums[mid]){
                lo++;
                hi--;
                continue;
            }
            if(nums[mid]<=nums[hi]){
                if(nums[mid]<=target && target<=nums[hi]){
                    lo=mid+1;
                }
                else{
                    hi=mid-1;
                }

            }
            else{
                if(nums[lo]<=target && target<=nums[mid]){
                    hi=mid-1;
                }
                else{
                    lo=mid+1;
                }
            }
        }
        return false;
        
    }
};