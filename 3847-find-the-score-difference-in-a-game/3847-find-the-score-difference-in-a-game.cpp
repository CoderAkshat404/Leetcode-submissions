class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int x=0;
        int y=0;
        int curr=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&1){
                curr=1-curr;

            }
            if((i+1)%6==0){
                curr=1-curr;
            }
            if(curr){
                y+=nums[i];
            }
            else{
                x+=nums[i];
            }
        }
        return x-y;
        
    }
};