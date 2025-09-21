class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size()-1;i++){
            int j=0;
            int k=nums.size()-1;
            while(j<i && k>i){
                if(nums[i]+nums[j]+nums[k]<0){
                    j++;
                }
                else if(nums[i]+nums[j]+nums[k]>0){
                    k--;
                }
                else if(nums[i]+nums[j]+nums[k]==0){
                    ans.insert({nums[j],nums[i],nums[k]});
                    j++;
                    k--;
                }
            }
        }
     vector<vector<int>> v(ans.begin(),ans.end());
     return v;   
    }
};