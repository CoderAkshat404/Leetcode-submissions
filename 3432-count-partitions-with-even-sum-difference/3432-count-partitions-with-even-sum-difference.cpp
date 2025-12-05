class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int totsum=0;
        for(auto i:nums){
            totsum+=i;
        }
        int ans=0;
        int rsum=0;
        for(auto i:nums){
            rsum+=i;
            if(abs(totsum-2*rsum)%2==0){
                ans++;
            }
        }
        return max(ans-1,0);
        
    }
};