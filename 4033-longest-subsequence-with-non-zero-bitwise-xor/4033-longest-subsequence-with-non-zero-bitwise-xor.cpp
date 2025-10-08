class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xori=0;
        bool allzero=true;
        for(auto i:nums){
            xori=xori ^ i;
            if(i!=0){
                allzero=false;
            }
        }
        if(xori==0){
            if(allzero==true){
                return 0;
            }
            else{
                return nums.size()-1;
            }
        }
        return nums.size();
    }
};