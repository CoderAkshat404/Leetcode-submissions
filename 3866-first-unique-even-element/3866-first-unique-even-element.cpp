class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        map<int,int> m;
        for(auto i:nums){
            m[i]++;
        }
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0 && m[nums[i]]==1){
                ans=nums[i];
                break;
            }
        }
        return ans;
        
    }
};