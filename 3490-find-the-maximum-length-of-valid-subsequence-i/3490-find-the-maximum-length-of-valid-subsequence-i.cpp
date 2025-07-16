class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int oddc=0;
        int evenc=0;
        for(auto i:nums){
            if(i&1){
                oddc++;
            }
            else{
                evenc++;
            }
        }
        int ans=oddc;
        ans=max(ans,evenc);
        int count=0;
        int state=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==state){
                count++;
                state=1-state;
            }
        }
        ans=max(ans,count);
        count=0;
        state=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==state){
                count++;
                state=1-state;
            }
        }
        ans=max(ans,count);
        return ans;
        
    }
};