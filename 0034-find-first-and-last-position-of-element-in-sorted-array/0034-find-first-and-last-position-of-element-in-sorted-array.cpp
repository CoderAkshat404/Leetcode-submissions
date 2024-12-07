class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0){
            return {-1,-1};
        }
        vector<int> ans;
        int left=0;
        int right=nums.size()-1;
        while(left<right){
            int mid=left + (right - left)/2;
            if(nums[mid]<target){
                left=mid+1;
            }
            if(nums[mid]>=target){
                right=mid;
            }
        }
        if(nums[right]==target){
            ans.push_back(right);
        }
        else{
            ans.push_back(-1);
        }
        left=0;
        right=nums.size()-1;
        while(left<right){
            int mid=left + (right - left+1)/2;
            if(nums[mid]<=target){
                left=mid;
            }
            if(nums[mid]>target){
                right=mid-1;
            }
        }
        if(nums[left]==target){
            ans.push_back(left);
        }
        else{
            ans.push_back(-1);
        }
      return ans;  
    }
};