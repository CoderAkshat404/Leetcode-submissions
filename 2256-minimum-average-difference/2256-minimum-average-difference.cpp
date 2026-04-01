class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        #define int long long
        int n=nums.size();
        vector<int> pre(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        int mini=1e9;
        int minidx=0;
        int totsum=pre.back();
        for(int i=0;i<n;i++){
            int left=pre[i]/(i+1);
            int right=0;
            if(i!=n-1){
            right=(totsum-pre[i])/(n-i-1);}
           if(abs(right-left)<mini){
            mini=abs(right-left);
            minidx=i;
           }
        }
        #undef int
        return minidx;
        
    }
};