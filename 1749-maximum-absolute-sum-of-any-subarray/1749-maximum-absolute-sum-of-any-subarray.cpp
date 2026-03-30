class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        map<int,int> m;
        m[0]=1;
        int sum=0;
        int ans=-1e9;
        int maxi=0;
        int mini=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            ans=max(ans,abs(sum-maxi));
            ans=max(ans,abs(sum-mini));
            maxi=max(maxi,sum);
            mini=min(mini,sum);
        }
        return ans;
        
    }
};