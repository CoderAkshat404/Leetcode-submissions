class Solution {
public:
    int solve(vector<int>& nums, int k){
        int n=nums.size();
        int l=0;
        int r=-1;
        int ans=0;
        int oddc=0;
        while(l<n){
            while(r+1<n && ((nums[r+1]&1 && oddc<k) || (nums[r+1]%2==0 && oddc<=k))){
                r++;
                if(nums[r]&1){
                    oddc++;
                }
            }
            ans+=r-l+1;
            if(r<l){
                l++;
                r=l-1;
            }
            else{
                if(nums[l]&1){
                    oddc--;
                }
                l++;
            }
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
        
    }
};