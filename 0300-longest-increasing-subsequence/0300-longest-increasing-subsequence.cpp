class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            if(v.size()==0){
                v.push_back(nums[i]);
            }
            else{
                if(v.back()<nums[i]){
                    v.push_back(nums[i]);
                }
                else{
                    int j=lower_bound(v.begin(),v.end(),nums[i])-v.begin();
                    v[j]=nums[i];

                }
            }
        }
        return v.size();
        
    }
};