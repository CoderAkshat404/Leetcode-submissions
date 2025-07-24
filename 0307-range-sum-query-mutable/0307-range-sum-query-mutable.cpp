class NumArray {
public:
    vector<int> t;
    int n;
    void solve(int index,int idx,int val,int l,int r){
        if(idx<l || idx>r){
            return ;
        }
        if(l==r){
            t[index]=val;
            return;
        }
        int mid=(l+r)/2;
        solve(2*index,idx,val,l,mid);
        solve(2*index+1,idx,val,mid+1,r);
        t[index]=t[2*index+1]+t[2*index];
    }
    int solve2(int index,int l,int r,int left,int right){
        if(right<l || left>r){
            return 0;
        }
        if(l>=left && r<=right){
            return t[index];
        }
        int mid=(l+r)/2;
        return solve2(2*index,l,mid,left,right)+solve2(2*index+1,mid+1,r,left,right);
    }
    void buildtree(int index,vector<int>& nums,int l,int r){
        if(l==r){
            t[index]=nums[l];
            return;
        }
        int mid=(l+r)/2;
        buildtree(2*index,nums,l,mid);
        buildtree(2*index+1,nums,mid+1,r);
        t[index]=t[2*index+1]+t[2*index];

    }
    NumArray(vector<int>& nums) {
        n=nums.size();
        t.resize(4*nums.size()+1);
        buildtree(1,nums,0,nums.size()-1);
        
    }
    
    void update(int index, int val) {
        solve(1,index,val,0,n-1);
        
    }
    
    int sumRange(int left, int right) {
        return solve2(1,0,n-1,left,right);
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */