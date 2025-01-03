class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long int> pre1(n-1);
        vector<long long int> pre2(n-1);
        pre1[0]=nums[0];
        for(int i=1;i<n-1;i++){
            pre1[i]=pre1[i-1]+nums[i];   
        }
        reverse(nums.begin(),nums.end());
        pre2[0]=nums[0];
        for(int i=1;i<n-1;i++){
            pre2[i]=pre2[i-1]+nums[i];   
        }
        reverse(pre2.begin(),pre2.end());
        long long int ans=0;
        for(int i=0;i<pre1.size();i++){
            if(pre1[i]>=pre2[i]){
                ans++;
            }
        } 
        return ans;
    }
};