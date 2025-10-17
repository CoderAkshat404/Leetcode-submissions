class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i+2*k-1<n;i++){
            bool flag1=true;
            bool flag2=true;
            for(int j=i+1;j<i+k;j++){
                if(nums[j]<=nums[j-1]){
                    flag1=false;
                    break;
                }
            }
            for(int j=i+k+1;j<i+2*k;j++){
                if(nums[j]<=nums[j-1]){
                    flag2=false;
                    break;
                }

            }
            if(flag1 && flag2){
                // cout<<"for i="<<i<<endl;
                return true;
            }

        }
     return false;   
    }
};