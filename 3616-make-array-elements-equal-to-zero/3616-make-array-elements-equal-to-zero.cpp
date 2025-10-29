class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int lsum=0;
            int rsum=0;
            if(nums[i]==0){
                if(i>0){
                    lsum=pre[i-1];
                }
                rsum=pre.back()-pre[i];
                 if(lsum==rsum ){
                ans+=2;}
                if(abs(lsum-rsum)==1){
                    ans++;
                }
            

            }
           
        }
        return ans;
    }
};