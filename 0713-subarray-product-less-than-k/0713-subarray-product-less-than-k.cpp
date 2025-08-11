class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l=0;
        int r=-1;
        int pro=1;
        int ans=0;
        int n=nums.size();
        while(l<n){
            while(r+1<n && pro*nums[r+1]<k){
                r++;
                pro*=nums[r];
            }
            ans+=(r-l+1);
            if(r<l){
                l++;
                r=l-1;
            }
            else{
                pro=pro/nums[l];
                l++;
            }
        }
        return ans;
        
    }
};