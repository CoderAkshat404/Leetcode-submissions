class Solution {
public:
    int solve(vector<int>& nums, int k){
        int oddc=0;
        int n=nums.size();
        int ans=0;
        int l=0;
        int r=-1;
        while(l<n){
            while(r+1<n && (nums[r+1]%2==0 || oddc<k)){
                r++;
                if(nums[r]%2){
                    oddc++;
                }
            }
            ans+=(r-l+1);
            if(l>r){
                l++;
                r=l-1;
            }
            else{
                if(nums[l]%2==1){
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