class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int x=0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size() && j!=i;j++){
                if(nums[i]==nums[j]){
                    x=x^nums[i];
                }
            }
        }
        return x;
        
    }
};