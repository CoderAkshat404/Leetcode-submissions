class Solution {
public:
    int check(int m,vector<int>& nums, int k){
        int x=1;
        int s=0;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
            if(s>m){
                s=nums[i];
                x++;
            }
        }
        if(x<=k){
            return 1;
        }
        else{
            return 0;
        }
    }
    int splitArray(vector<int>& nums, int k) {
        int s=0;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
            maxi=max(maxi,nums[i]);
        }
        int lo=maxi;
        int hi=s;
        int ans=-1;
        while(lo<=hi){
            int m=lo+(hi-lo)/2;
            if(check(m,nums,k)==1){
                hi=m-1;
                ans=m;
            }
            else{
                lo=m+1;
            }
        }
        return ans;
        
    }
};