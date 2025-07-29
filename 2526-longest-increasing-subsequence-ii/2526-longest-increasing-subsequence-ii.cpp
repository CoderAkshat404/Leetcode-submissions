class Solution {
public:
    void update(int id,int l,int r,int val,int pos,vector<int> & t){
        if(pos<l || pos>r){
            return ;
        }
        if(l==r){
            t[id]=max(t[id],val);
            return ;
        }
        int mid=(l+r)/2;
        update(2*id,l,mid,val,pos,t);
        update(2*id+1,mid+1,r,val,pos,t);
        t[id]=max(t[2*id],t[2*id+1]);

    }
    int query(int id,int l,int r,int left,int right,vector<int> & t){
        if(right<l || left>r){
            return 0;
        }
        if(left<=l && right>=r){
            return t[id];
        }
        int mid=(l+r)/2;
        return max(query(2*id,l,mid,left,right,t),query(2*id+1,mid+1,r,left,right,t));
    }
    int lengthOfLIS(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> t(400400,0);
        vector<int> dp(n);
        int ans=0;
        for(int i=0;i<n;i++){
            int lo=max(0,nums[i]-k);
            int hi=nums[i]-1;
            int x=0;
            if(hi>=lo){
                x=query(1,0,100100,lo,hi,t);
            }
            dp[i]=x+1;
            ans=max(ans,dp[i]);
            update(1,0,100100,dp[i],nums[i],t);
        }
        return ans;
        
    }
};