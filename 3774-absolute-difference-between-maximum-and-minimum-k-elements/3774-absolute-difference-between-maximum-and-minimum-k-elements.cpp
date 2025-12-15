class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ks=0;
        for(int i=0;i<k;i++){
            ks+=nums[i];
        }
        sort(nums.rbegin(),nums.rend());
        int kl=0;
        for(int i=0;i<k;i++){
            kl+=nums[i];
        }
        return abs(ks-kl);
        
    }
};