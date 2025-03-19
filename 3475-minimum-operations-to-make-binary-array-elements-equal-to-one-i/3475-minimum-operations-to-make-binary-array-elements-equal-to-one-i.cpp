class Solution {
public:
    bool allone(vector<int>& nums){
        for(int i:nums){
            if(i==0){
                return false;
            }
        }
        return true;
    }
    int minOperations(vector<int>& nums) {
        int op = 0;
        // if(nums.size()%3!=0 && !allone(nums)){
        //     return -1;
        // }
        int i = 0;
        while(i<nums.size()-2){
            if(nums[i]==0){
                nums[i] = 1;
                nums[i+1] = (nums[i+1])? 0 : 1;
                nums[i+2] = (nums[i+2])? 0 : 1;
                 op++;
            }
            i++;  
        }
        if(!allone(nums))   return -1;
        return op;
    }
};