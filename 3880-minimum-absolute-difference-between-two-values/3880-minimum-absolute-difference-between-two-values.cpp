class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int mini=1e9;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(nums[i]==1 && nums[j]==2){
                    mini=min(mini,abs(i-j));
                }
            }
        }
        if(mini==1e9){
            return -1;
        }
        return mini;
        
    }
};