class Solution {
public:
    bool check(int mid,vector<int>& nums, int k){
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            int req=mid+nums[i];
           
            cnt += upper_bound(nums.begin()+i+1, nums.end(), req) - (nums.begin()+i+1);
           
        }
        return cnt>=k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int lo=0;
        int hi=1e9;
        int ans=-1;
       
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(mid,nums,k)){
                hi=mid-1;
                ans=mid;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
        
    }
};