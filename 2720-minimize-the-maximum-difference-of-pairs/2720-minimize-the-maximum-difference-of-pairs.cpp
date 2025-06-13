class Solution {
public:
    bool check(int m,vector<int>& nums, int p){
        int cnt=0;
        for(int i=0;i<nums.size()-1;i++){
            if(abs(nums[i]-nums[i+1])<=m){
                cnt++;
                i++;

            }
           
        }
        return cnt>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int lo=0;
        int hi=1e9;
        int ans=-1;
        while(lo<=hi){
            int m=lo+(hi-lo)/2;
            if(check(m,nums,p)){
                hi=m-1;
                ans=m;
            }
            else{
                lo=m+1;
            }
        }
        return ans;
        
    }
};