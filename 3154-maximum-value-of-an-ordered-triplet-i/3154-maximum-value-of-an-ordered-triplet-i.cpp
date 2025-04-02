class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans=-1e18;
        for(long long i=0;i<nums.size()-2;i++){
            for(long long j=i+1;j<nums.size()-1;j++){
                for(long long k=j+1;k<nums.size();k++){
                    long long x=(nums[i]-nums[j]);
                    long long y=x*nums[k];
                    ans=max(ans,y);
                }
            }
        }
        if(ans<0) return 0;
        return ans;
        
    }
};