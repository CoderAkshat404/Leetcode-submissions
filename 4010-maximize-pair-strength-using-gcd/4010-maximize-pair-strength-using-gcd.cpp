class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long maxi=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                maxi=max(maxi,(1LL*nums[i]*nums[j])/(1LL*__gcd(nums[i],nums[j])*__gcd(nums[i],nums[j])));
            }
        }
        return maxi;
        
    }
};