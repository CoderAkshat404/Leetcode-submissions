class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int lo=0;
        int hi=nums.size()-1;
        int ans=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]<nums[0]){
                hi=mid-1;
                ans=mid;

            }
            else{
                lo=mid+1;
            }
        }
       
        int ch1=lower_bound(nums.begin(),nums.begin()+ans,target)-(nums.begin());
        int ch2=lower_bound(nums.begin()+ans,nums.end(),target)-(nums.begin());
        
        if(ch1!=n && nums[ch1]==target){
            return ch1;
        }
        if(ch2!=n && nums[ch2]==target){
            return ch2;
        }
        return -1;

        
    }
};