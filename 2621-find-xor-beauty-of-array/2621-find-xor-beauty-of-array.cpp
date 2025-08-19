class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int xori=0;
        for(auto i:nums){
            xori=xori^i;
        }
        return xori;
        
    }
};