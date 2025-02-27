class Solution {
public:
    int check(int div,vector<int>& nums, int threshold){
        int sum=0;
        for(auto i:nums){
            sum+=(i+div-1)/div;
        }
        if(sum<=threshold){
            return 1;

        }
       
            return 0;
        
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi=INT_MIN;
        for(auto i:nums){
            maxi=max(i,maxi);
        }
        int lo=1;
        int hi=maxi;
        int ans=0;
        while(lo<=hi){
            int m=lo+(hi-lo)/2;
            if(check(m,nums,threshold)){
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