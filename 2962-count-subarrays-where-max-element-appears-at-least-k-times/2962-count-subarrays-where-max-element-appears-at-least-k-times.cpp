class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi=0;
        for(auto i:nums){
            maxi=max(maxi,i);
        }
        int l=0;
        int r=-1;
        long long ans=0;
        int n=nums.size();
        int cnt=0;
        while(l<n){
            while(r+1<n && (cnt<k)){
                r++;
                if(nums[r]==maxi){
                    cnt++;
                }
            }
            if(cnt==k){
                ans+=n-r;
            }
            if(l>r){
                l++;
                r=l-1;
            }
            else{
                if(nums[l]==maxi) cnt--;
                l++;
            }
        }
        return ans;
        
    }
};