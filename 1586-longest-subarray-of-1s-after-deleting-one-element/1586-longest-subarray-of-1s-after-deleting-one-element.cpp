class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeroc=0;
        int l=0;
        int r=-1;
        int n=nums.size();
        int ans=0;
        while(l<n){
            while(r+1<n && (zeroc==0 || nums[r+1]==1)){
                r++;
                if(nums[r]==0){
                    zeroc++;
                }
            }
            ans=max(ans,r-l);
            if(r<l){
                l++;
                r=l-1;
            }
            else{
                if(nums[l]==0){
                    zeroc--;
                }
                l++;
            }

        }
        return ans;
        
    }
};