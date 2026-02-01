class Solution {
public:
    bool check(int mid,vector<int>& nums){
        int x=0;
        long long limit=1LL*mid*mid;
        for(auto i:nums){
            x+=(i+mid-1)/mid;
        }
        return x<=limit;
    }
    int minimumK(vector<int>& nums) {
        int lo=1;
        int hi=1e5;
        int ans=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(mid,nums)){
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