class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int pre=1;
        int cnt=1;
        int maxi=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                cnt++;
            }
            else{
                maxi=max(maxi,min(pre,cnt));
                pre=cnt;
                maxi=max(maxi,cnt/2);
                cnt=1;
            }
        }
        maxi=max(maxi,min(pre,cnt));
        maxi=max(maxi,cnt/2);
        return maxi;
        
    }
};