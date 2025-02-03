class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int count=1;
        int maxi=1;
        int prev=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>prev){
                count++;
                prev=nums[i];
                maxi=max(maxi,count);
            }
            else {
                count=1;
                prev=nums[i];
            }

        }
        maxi=max(maxi,count);
        count=1;
        prev=nums.back();
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]>prev){
                count++;
                prev=nums[i];
                maxi=max(maxi,count);
            }
            else {
                count=1;
                prev=nums[i];
            }
            
        }
        maxi=max(maxi,count);
     return maxi;   
    }
};