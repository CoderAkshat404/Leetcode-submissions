class Solution {
public:
    long long gcdSum(vector<int>& nums) {
       
        int n=nums.size();
        int maxi=0;
        vector<int> pre(n);
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
            pre[i]=__gcd(nums[i],maxi);
        }
        sort(pre.begin(),pre.end());
        int i=0;
        int j=n-1;
        long long ans=0;
        while(i<j){
            ans+=__gcd(pre[i],pre[j]);
            i++;
            j--;
        }
        return ans;
       

        
    }
};