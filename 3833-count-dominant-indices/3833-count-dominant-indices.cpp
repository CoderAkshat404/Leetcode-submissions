class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n=nums.size();
        vector<int> suff(n);
        suff[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suff[i]=nums[i]+suff[i+1];
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            double avg=(double)suff[i+1]/(double)(n-(i+1));
            if(nums[i]>avg){
                ans++;
            }
        }
        return ans;
        
    }
};