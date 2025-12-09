class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int idx=upper_bound(nums.begin(),nums.end(),nums[i])-nums.begin();
            int x=nums.size()-idx;
            if(x>=k){
                ans++;
            }
        
        }
        return ans;
        
    }
};