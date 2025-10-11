class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int count=2;
        int ans=2;
        int a=0;
        int b=1;
        while((b+1)<nums.size()){
            if(nums[a]+nums[b]==nums[b+1]){
                count++;
                ans=max(ans,count);
                a=b;
                b=b+1;
            }
            else{
                count=2;
                a=b;
                b++;
            }

        }
        return ans;
    }
};