class Solution {
public:
    vector<int> pre;
    bool check(long long mid,vector<int>& nums,int l,int r,int k){
    long long x=mid/2;

    int ub = upper_bound(nums.begin()+l, nums.begin()+r+1, mid) - nums.begin();
    ub--;

    if(ub>=l && ub<=r){
        int y=pre[ub];
        if(l-1>=0){
            y-=pre[l-1];
        }
        x-=y;
    }

    return (x>=k);
}
    vector<int> kthRemainingInteger(vector<int>& nums, vector<vector<int>>& q) {
        int n=nums.size();
        vector<int> res;
        pre.resize(n);
        pre[0]=(nums[0]%2==0);
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+(nums[i]%2==0);
        }
        for(int i=0;i<q.size();i++){
            int l=q[i][0];
            int r=q[i][1];
            int k=q[i][2];
            long long lo=2;
            long long hi=1e18;
            long long ans=-1;
            while(lo<=hi){
                long long mid=(lo+hi)/2;
                if(check(mid,nums,l,r,k)){
                    hi=mid-1;
                    ans=mid;
                }
                else{
                    lo=mid+1;
                }
            }
            res.push_back(ans);
            
        }
        return res;
    }
};