class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        
        int cxor=0;
        for(int i=0;i<nums.size();i++){
            cxor=cxor | nums[i];
        }
        return cxor;
        
    }
};