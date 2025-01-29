class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n);
        pre[0]=nums[0];
        int sum=0;
        sum+=nums[0];
        for(int i=1;i<nums.size();i++){
            pre[i]=pre[i-1]+nums[i];
            sum+=nums[i];
        }
        int ans=-1;
        for(int i=0;i<n;i++){
            int lsum=0;
            int rsum=0;
            if(i==0){
                lsum=0;
                rsum=sum-pre[0];

            }
            else if(i==n-1){
                lsum=sum-nums[i];
                rsum=0;
            }
            else{
                lsum=pre[i-1];
                rsum=sum-pre[i];
            }
            if(lsum==rsum){
                ans=i;
                break;
            }
        }
        return ans;
        
    }
};