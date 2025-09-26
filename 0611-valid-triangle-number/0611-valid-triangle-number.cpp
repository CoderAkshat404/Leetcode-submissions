class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=2;i<nums.size();i++){
            for(int j=i-1;j>=1;j--){
                int target=nums[i]-nums[j];
                int x=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
                int y=j-1-x+1;
                if(y>=0){
                    ans+=y;
                }
            }
        }
        return ans;
        
    }
};