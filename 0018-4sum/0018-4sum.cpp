class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<=3){
            return {};
        }
        set<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size()-2;i++){
            for(int p=i+1;p<nums.size()-1;p++){
            int j=0;
            int k=nums.size()-1;
            while(j<i && k>p){
                if((long long)nums[i]+nums[j]+nums[k]+nums[p]<target){
                    j++;
                }
                else if((long long)nums[i]+nums[j]+nums[k]+nums[p]>target){
                    k--;
                }
                else if((long long)nums[i]+nums[j]+nums[k]+nums[p]==target){
                    ans.insert({nums[j],nums[i],nums[p],nums[k]});
                    j++;
                    k--;
                }
            }
        }
        }
     vector<vector<int>> v(ans.begin(),ans.end());
     return v;   
        
    }
};