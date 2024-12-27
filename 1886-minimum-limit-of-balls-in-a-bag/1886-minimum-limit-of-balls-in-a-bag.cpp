class Solution {
public:
    int check(int m,vector<int>& nums, int maxOperations){
        int x=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%m==0){
                x+=nums[i]/m;
                x--;
            }
            else{
                x+=nums[i]/m;
            }
        }
        if(x<=maxOperations){
            return 1;
        }
        else{
            return 0;
        }
        
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
        }
        int lo=1;
        int hi=maxi;
        int ans=-1;
        while(lo<=hi){
            int m=lo+(hi-lo)/2;
            if(check(m,nums,maxOperations)==1){
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