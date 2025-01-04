class Solution {
public:
    int check(int m,int target, vector<int>& nums){
        int s=0;
        for(int i=0;i<m;i++){
            s+=nums[i];
        }
        if(s>=target){
            return 1;
        }
        int i=0;
        int j=m-1;
        while(j+1<nums.size()){
            s+=nums[j+1];
            s-=nums[i];
            i++;
            j++;
            if(s>=target){
                return 1;
            }

        }
        return 0;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        int lo=1;
        int hi=nums.size();
        int ans=0;
        while(lo<=hi){
            int m=lo+(hi-lo)/2;
            if(check(m,target,nums)==1){
                ans=m;
                hi=m-1;
            }
            else{
                lo=m+1;
            }
        }
        return ans;

        
    }
};