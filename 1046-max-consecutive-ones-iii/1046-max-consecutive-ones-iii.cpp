class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int onec=0;
        int zeroc=0;
        int l=0;
        int r=-1;
        int ans=0;
        while(l<n){
            while(r+1<n && (nums[r+1]==1 || (nums[r+1]==0 && zeroc<k))){
                r++;
                if(nums[r]==0){
                    zeroc++;
                }
                else{
                    onec++;
                }
            }
            ans=max(ans,r-l+1);
            if(r<l){
                l++;
                r=l-1;
            }
            else{
                if(nums[l]==0){
                    zeroc--;
                }
                else{
                    onec--;
                }
                l++;
            }

        }
        return ans;
        
    }
};