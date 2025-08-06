class Solution {
public:
    int t[400400];
    void build(int idx,int l,int r,vector<int>& baskets){
        if(l==r){
            t[idx]=baskets[l];
            return;
        }
        int mid=(l+r)/2;
        build(2*idx,l,mid,baskets);
        build(2*idx+1,mid+1,r,baskets);
        t[idx]=max(t[2*idx],t[2*idx+1]);
    }
    void update(int idx,int l,int r,int pos,int val){
        if(l==r){
            t[idx]=val;
            return;
        }
        int mid=(l+r)/2;
        if (pos <= mid) {
            update(idx << 1, l, mid, pos, val);
        } else {
            update(idx << 1 | 1, mid + 1, r, pos, val);
        }
        t[idx]=max(t[2*idx],t[2*idx+1]);
    }
    int query(int idx,int l,int r,int left,int right){
        if(left>r || right<l){
            return INT_MIN;
        }
        if(left<=l && r<=right){
            return t[idx];
        }
        int mid=(l+r)/2;
        return max(query(2*idx,l,mid,left,right),query(2*idx+1,mid+1,r,left,right));

    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=baskets.size();
        build(1,0,n-1,baskets);
        int ans=0;
        for(int i=0;i<n;i++){
            int lo=0;
            int hi=n-1;
            int def=-1;
            while(lo<=hi){
                int mid=(lo+hi)/2;
                if(query(1,0,n-1,0,mid)>=fruits[i]){
                    def=mid;
                    hi=mid-1;
                }
                else{
                    lo=mid+1;
                }
            }
            if(def!=-1){
                update(1,0,n-1,def,INT_MIN);
            }
            else{
                ans++;
            }

        }
        return ans;
        
    }
};