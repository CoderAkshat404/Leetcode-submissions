class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        #define int long long
        int ans=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                cnt++;
            }
            else{
                ans+=(cnt*(cnt+1))/2;
                cnt=0;
            }
        }
        ans+=(cnt*(cnt+1))/2;
        return ans;
        #undef int
        
    }
};