class Solution {
public:
    int check(int m,vector<int>& nums, int k){
        int count=0;
        int i=0;
        while(i<nums.size()){
            if(nums[i]<=m){
                count++;
                i+=2;
            }
            else{
                i++;
            }
        }
        if(count>=k) return 1;
        else return 0;
    }
    int minCapability(vector<int>& nums, int k) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(auto i:nums){
            mini=min(mini,i);
            maxi=max(maxi,i);
        }
        int lo=mini;
        int hi=maxi;
        int ans=-1;
        while(lo<=hi){
            int m=lo+(hi-lo)/2;
            if(check(m,nums,k)){
                ans=m;
                hi=m-1;

            }
            else{
                lo=m+1;
            }
        }
        return ans;
        
    }
};