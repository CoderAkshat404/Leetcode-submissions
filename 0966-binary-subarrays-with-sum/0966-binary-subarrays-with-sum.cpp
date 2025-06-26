class Solution {
public:
    int solve(vector<int>& nums, int goal){
        int n=nums.size();
        int l=0;
        int r=-1;
        int sum=0;
        int ans=0;
        while(l<n){
            while(r+1<n && nums[r+1]+sum<=goal){
                r++;
                sum+=nums[r];
            }
            ans+=r-l+1;
            if(r<l){
                l++;
                r=l-1;
            }
            else{
                sum-=nums[l];
                l++;

            }


        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums,goal)-solve(nums,goal-1);
        
    }
};