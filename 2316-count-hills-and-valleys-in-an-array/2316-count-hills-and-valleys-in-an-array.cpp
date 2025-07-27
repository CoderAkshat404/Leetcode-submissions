class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans=0;
        for(int i=1;i<nums.size()-1;i++){
            int prev=i-1;
            int forw=i+1;
            while(prev>=0 && nums[prev]==nums[i]){
                prev--;
            }
            while(forw<nums.size() && nums[forw]==nums[i]){
                forw++;   
            }
            if(prev>=0 && forw<nums.size()){
                if(nums[prev]<nums[i] && nums[forw]<nums[i]){
                    ans++;
                }
                if(nums[prev]>nums[i] && nums[forw]>nums[i]){
                    ans++;
                }
            }
            i=forw-1;


        }
        return ans;
        
    }
};